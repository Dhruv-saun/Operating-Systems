// wap to open a file in child process and write even numbers up to n and then pass file name using pipe and read and print the content in parent process
#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	int pipefd[2];
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return 1;
	}

	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return 1;
	}

	const char *fileName = "even_numbers.txt";

	if (pid == 0)
	{
		close(pipefd[0]);

		ofstream outputFile(fileName);
		if (!outputFile)
		{
			perror("open file");
			close(pipefd[1]);
			return 1;
		}

		for (int number = 2; number <= n; number += 2)
			outputFile << number << ' ';
		outputFile.close();

		write(pipefd[1], fileName, strlen(fileName) + 1);
		close(pipefd[1]);
		return 0;
	}

	close(pipefd[1]);

	char receivedFileName[100]{};
	ssize_t bytesRead = read(pipefd[0], receivedFileName,
							 sizeof(receivedFileName) - 1);
	close(pipefd[0]);

	waitpid(pid, nullptr, 0);

	if (bytesRead <= 0)
	{
		cerr << "Could not receive the file name from the child process.\n";
		return 1;
	}

	ifstream inputFile(receivedFileName);
	if (!inputFile)
	{
		perror("open file");
		return 1;
	}

	cout << "Content of " << receivedFileName << ":\n";
	string content;
	getline(inputFile, content);
	cout << content << '\n';

	return 0;
}
