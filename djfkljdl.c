/*
 * Problem 1: Basic File Operations
 *
 * Requirements:
 * 1. Create "student_info.txt" and write student information
 * 2. Reopen the file and print its contents to the screen
 * 3. Handle all error situations appropriately
 *
 * Learning Objectives:
 * - Understand various parameters of CreateFile
 * - Use WriteFile and ReadFile
 * - Manage file handles and error handling
 */

#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hFile;
    DWORD dwBytesWritten, dwBytesRead;
    char studentInfo[] = "Name: Hong Gil-dong\nStudent ID: 20240001\nMajor: Computer Engineering\n";
    char readBuffer[256];

    printf("=== Problem 1: Basic File Operations ===\n\n");

    // TODO 1: Create "student_info.txt" with write permission
    // CreateFile 함수를 사용하여 파일을 생성하세요
    // 힌트: dwCreationDisposition에 CREATE_ALWAYS 사용
    hFile = CreateFile("student_info.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        /* 여기에 CreateFileA 함수 호출을 작성하세요 */;

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("File creation failed: %d\n", GetLastError());
        return 1;
    }

    // TODO 2: Write studentInfo to the file
    // WriteFile 함수를 사용하세요
    // 힌트: WriteFile(hFile, studentInfo, sizeof(studentInfo) - sizeof(wchar_t), &dwBytesWritten, NULL)
    /* 여기에 WriteFile 함수 호출과 에러 처리를 작성하세요 */
    if (WriteFile(hFile, studentInfo, sizeof(studentInfo) - sizeof(char), &dwBytesWritten, NULL)) {
        printf("Write completed: %d\n", dwBytesWritten);
    }
    else {
        printf("Write failed");
    }

    printf("Successfully wrote %d bytes to the file.\n", dwBytesWritten);
    CloseHandle(hFile);

    // TODO 3: Reopen the file for reading
    // CreateFile을 GENERIC_READ와 OPEN_EXISTING으로 사용
    hFile = CreateFile("student_info.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        /* 여기에 CreateFileA 함수 호출을 작성하세요 (읽기 모드) */;

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("File open failed: %d\n", GetLastError());
        return 1;
    }

    // TODO 4: Read file contents and print to screen
    // ReadFile 함수를 사용하세요
    // 힌트: ReadFile(hFile, readBuffer, sizeof(readBuffer) - sizeof(wchar_t), &dwBytesRead, NULL)
    /* 여기에 ReadFile 함수 호출과 결과 출력을 작성하세요 */
    /* 힌트: readBuffer[dwBytesRead] = '\0'; 로 문자열 종료 */
    /* printf("\nRead from file (%d bytes):\n%s\n", dwBytesRead, readBuffer); */
    if (ReadFile(hFile, readBuffer, sizeof(readBuffer) - sizeof(char), &dwBytesRead, NULL)) {
        readBuffer[dwBytesRead] = '\0';
        printf("\nRead from file (%d bytes) :\n%s\n", dwBytesRead, readBuffer);
    }
    else {
        printf("Read failed\n");
    }

    CloseHandle(hFile);

    printf("\nPractice complete!\n");
    printf("Created file: student_info.txt\n");

    return 0;
}

/*
 * Practice Tasks:
 * 1. Complete the TODO sections above
 * 2. Change the student information to something else
 * 3. Check behavior when the file already exists
 * 4. Test with an invalid filename to check error handling
 *
 * Additional Challenges:
 * - Save and read information for multiple students
 * - Check file size using GetFileSize
 */