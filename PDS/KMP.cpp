#include "const.cpp"
int next1[255];
void get_next(char t[])
{
	int i = 1;
	next1[1] = 0;
	int j = 0;
	while (i < strlen(t) - 1)
	{
		if (j == 0 || t[i] == t[j])
		{
			++i;
			++j;
			next1[i] = j;
		}
		else
			j = next1[j];
	}
}
int Index_KMP(char str[], char t[], int pos)
{
	int i = pos, j = 1;
	while (i <= strlen(str) - 1 && j <= strlen(t) - 1)
	{
		if (j == 0 || str[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next1[j];
		}
	}
	if (j > strlen(t) - 1)
		return i - strlen(t) + 1;
	else
		return 0;
}
int main()
{
	char str[20] = "#abababcaabaabcac";
	char t[100] = "#abaabcac";
	get_next(t);
	cout << str + Index_KMP(str, t, 1) << endl;
	return 0;
}
