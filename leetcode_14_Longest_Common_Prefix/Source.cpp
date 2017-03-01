#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	int lcpLen = 0;
	if (strsSize == 1)
		return strs[0];

	for (int i = 0; i < strsSize - 1; i++) {
		int j = 0;
		if (!strcmp(strs[i], ""))
			return "";
		int commonLen = 0;
		while (strs[i][j] == strs[i + 1][j] && (!strs[i][j] || !strs[i + 1][j])) {
			commonLen++;
			j++;
		}
		if (commonLen < lcpLen || lcpLen == 0)
			lcpLen = commonLen;
	}
	char *lcp = (char*)calloc(lcpLen, sizeof(char));

	memcpy(lcp, strs[0], lcpLen);
	return lcp;
}

int main() {
	char *inputStrs[2]= { "c","c" };

	printf("%s", longestCommonPrefix(inputStrs, 2));
	return 0;
}