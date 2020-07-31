#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#include <time.h>

#include <string.h>

#include <wchar.h>

#include <Windows.h>

int s32_AnalysisView = 0;
int nRes = 0;
int s32_DebugMode = 0;

int DecideMyNum(int * plength)

{
	int s32_subRes1 = 0;
	int s32_subRes2 = 0;
	int s32_subRes3 = 0;
	int* ars32_subArr1 = NULL;
	int* ars32_subArr2 = NULL;
	int* ars32_subArr3 = NULL;

	int nResult = 0;

	int a[10] = { 0 };

	int bFound = 0;



	printf("�� �ڸ� ���ڷ� ������ �ϰڽ��ϱ�?(2~7�ڸ�)\n");

	scanf_s("%d", plength);



	while (*plength <= 0 || *plength > 7)

	{

		printf("��ȿ�� �ڸ����� �Է����ּ���: \n");

		scanf_s("%d", plength);

	}

	printf("�������� ������ �����ϰڽ��ϱ�?: \n");
	scanf_s("%d", &s32_DebugMode);

	if (s32_DebugMode == 0)
	{
		printf("���� �� �ĺ����� ���ðڽ��ϱ�?: \n");
		scanf_s("%d", &s32_AnalysisView);
	}
	else
	{
		s32_AnalysisView = 1;
	}

	
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < *plength; ++i)
		{
			while (1)
			{
				// �������ϳ�����
				a[i] = rand() % 10;

				// �̹��ִ°�����Ȯ���ϱ������÷��׼���
				bFound = 0;

				// ���������ִ���Ȯ���Ѵ�
				for (int j = 0; j < i; ++j)
				{
					// ��������������
					if (a[j] == a[i])
					{
						// ���������̹�����
						bFound = 1;
						break;
					}
				}
				// �������̾�����while��Ż��
				if (!bFound)
					break;

			}
		}
		ars32_subArr1 = (int*)malloc(sizeof(int)*(*plength));
		ars32_subArr2 = (int*)malloc(sizeof(int)*(*plength));
		ars32_subArr3 = (int*)malloc(sizeof(int)*(*plength));

		for (int i = 0; i < *plength; i++)
		{
			if (k==0)
			{
				
				s32_subRes1 = s32_subRes1 + (int)(a[i] * (int)pow(10, i));
				for (int m = 0; m < *plength; m++)
				{
					ars32_subArr1[m] = (s32_subRes1 / (int)(pow(10, m))) - (s32_subRes1 / (int)(pow(10, m + 1)) * 10);
				}
			}
			else if (k==1)
			{
				s32_subRes2 = s32_subRes2 + (int)(a[i] * (int)pow(10, i));
				for (int m = 0; m < *plength; m++)
				{
					ars32_subArr2[m] = (s32_subRes2 / (int)(pow(10, m))) - (s32_subRes2 / (int)(pow(10, m + 1)) * 10);
				}
			}
			else if (k==2)
			{
				
				s32_subRes3 = s32_subRes3 + (int)(a[i] * (int)pow(10, i));
				for (int m = 0; m < *plength; m++)
				{
					ars32_subArr3[m] = (s32_subRes3 / (int)(pow(10, m))) - (s32_subRes3 / (int)(pow(10, m + 1)) * 10);
				}
			}
		}
	}
	
	nResult = s32_subRes1;
	// �� �� ���� ���߱� ����� ���ڸ� ��


	return nResult;

}



int GetGuessNum(int * arrGuessNum, int nRound, int length)

{

	while (1)

	{

		printf("������ %d�ڸ� ���ڸ� �Է����ּ���: \n", length);

		scanf_s("%d", &arrGuessNum[nRound]);



		if (((arrGuessNum[nRound]) > (int)(pow(10, length - 2))) && ((arrGuessNum[nRound]) < (int)(pow(10, length))))

		{

			break;

		}

		printf("��ȿ�� �ڸ����� �ƴմϴ�\n");

	}
	return 1;
}



int ShowGuessResult(int MyNumber, int HerGuess, int nLen, int * arrResultFlag)

{

	int i = 0, j = 0;

	int TargetNumber = 0;

	int CompareNumber = 0;



	arrResultFlag[0] = 0;

	arrResultFlag[1] = 0;



	for (j = 0; j < nLen; j++)

	{

		TargetNumber = (HerGuess / (int)(pow(10, j))) - (HerGuess / (int)(pow(10, j + 1)) * 10);



		for (i = 0; i < nLen; i++)

		{

			CompareNumber = (MyNumber / (int)(pow(10, i))) - (MyNumber / (int)(pow(10, i + 1)) * 10);

			if ((i == j) && (TargetNumber == CompareNumber))

			{

				arrResultFlag[0]++;

			}

			else if ((TargetNumber == CompareNumber))

			{

				arrResultFlag[1]++;

			}

		}

	}



	printf("��Ʈ����ũ: %d\n", arrResultFlag[0]);

	printf("��: %d\n\n", arrResultFlag[1]);

	if (arrResultFlag[0] == nLen)
	{

		printf("����� ���ӿ� �¸��߽��ϴ�!!! �����մϴ�!!\n");

		printf("(1000�� �� �����մϴ�...)\n");
		printf("PC answer: %d\n", nRes);
		Sleep(1000000);

		return 1;
	}
	else

	{

		return 0;

	}

}



int InitCandidates(int length, int * arrCandidates, int * pHowManyCandidates)

{

	int CandiNum = 0;

	int TargetNumber = 0, CompareNumber = 0;

	CandiNum = 0;



	while (CandiNum < pow(10, length))

	{

		CandiNum++;

		if (CandiNum >= pow(10, length))

		{

			break;

		}

		for (int j = 0; j < length - 1; j++)

		{

			TargetNumber = (CandiNum / (int)(pow(10, j))) - (CandiNum / (int)(pow(10, j + 1)) * 10);

			for (int i = j + 1; i < length; i++)

			{

				CompareNumber = (CandiNum / (int)(pow(10, i))) - (CandiNum / (int)(pow(10, i + 1)) * 10);

				if ((TargetNumber == CompareNumber))

				{

					break;

				}

			}

			if ((TargetNumber == CompareNumber))

			{

				break;

			}

			if (j == length - 2)

			{

				//printf("%d\n", CandiNum);

				*(arrCandidates + (*pHowManyCandidates)) = CandiNum;

				(*pHowManyCandidates) = (*pHowManyCandidates) + 1;

			}

		}



	}
	return 1;


	/*for (int i = 0; i < *pHowManyCandidates; i++)

	{

	printf("%d ", *(arrCandidates + i));

	}*/

}





int ShowGuessNumber(int * arrCandidates, int * pHowManyRealCandidates, int * pnMyChoice, int * pfStartIdx)

{

	int fHit = 0;
	int *PssbIdxList = NULL;
	int Listidx = 0;
	int s32_NumOfPossibleCands = 0;

	for (int i = 0; i < *pHowManyRealCandidates; i++)

	{

		//printf("%d\n", *(arrCandidates + i));

		if (*(arrCandidates + i) != 0)

		{
			s32_NumOfPossibleCands++;
		}
	}
	PssbIdxList = (int*)malloc(sizeof(int)*s32_NumOfPossibleCands);
	Listidx = 0;
	for (int i = *pfStartIdx; i < *pHowManyRealCandidates; i++)

	{

		//printf("%d\n", *(arrCandidates + i));

		if (*(arrCandidates + i) != 0)

		{
			PssbIdxList[Listidx] = i;
			Listidx++;
		}
	}


	// �ĺ� ���� ���
	if (s32_NumOfPossibleCands == 1)
	{
		Listidx = 0;

	}
	else if (s32_NumOfPossibleCands == 0)
	{
		printf("�ĺ��� ����!!\n");
		Listidx = 0;
	}
	else
	{
		Listidx = rand() % s32_NumOfPossibleCands;
	}

	*pnMyChoice = *(arrCandidates + PssbIdxList[Listidx]);

	// End


	*pfStartIdx = 0;


	if (*pnMyChoice == 0)
	{
		fHit = 0;
	}
	else
	{
		fHit = 1;
	}





	if (fHit == 1)

	{

		if (s32_NumOfPossibleCands == 1)

		{
			printf("����� ���� ������ �̰��Դϴ�: %d\n", *pnMyChoice);
			printf("�� ������ %d �Դϴ�\n", nRes);
			printf("(1000�� �� �����մϴ�...)\n");

			Sleep(1000000);

			return -1;

		}
		else
		{

			printf("�µ��̰� ������ ���ڴ� �̰��Դϴ�: %d\n", *pnMyChoice);
			return 1;
		}
	}
	else
	{

		printf("�߸��� ������ �ּż� ������ �����մϴ�...\n");
		printf("�� ������ %d �Դϴ�\n", nRes);
		printf("(1000�� �� �����մϴ�...)\n");

		Sleep(1000000);


		return -1;

	}



}



int GetGuessResult(int * arrCandidates, int * pHowManyRealCandidates, int * pnStrikes, int * pnBalls)

{

	char fSure = 'N';

	while ((fSure == 'N') || (fSure == 'n'))

	{

		printf("��Ʈ����ũ�� ��ΰ���?: ");

		scanf_s("%d", pnStrikes);

		printf("���� ��ΰ���?: ");

		scanf_s("%d", pnBalls);

		printf("Ȯ���� �Է��߳���?(Y/N) : ");

		getchar();

		scanf_s("%c", &fSure);

	}



	return 0;

}



int CompareNums(int n1, int n2, int length, int nStrikes, int nBalls)

{

	int TargetNumber = 0;

	int CompareNumber = 0;

	int nTempStrikes = 0;

	int nTempBalls = 0;



	for (int j = 0; j < length; j++)

	{

		TargetNumber = (n1 / (int)(pow(10, j))) - (n1 / (int)(pow(10, j + 1)) * 10);

		for (int i = 0; i < length; i++)

		{

			CompareNumber = (n2 / (int)(pow(10, i))) - (n2 / (int)(pow(10, i + 1)) * 10);

			if ((i == j) && (TargetNumber == CompareNumber))

			{

				nTempStrikes++;

				break;

			}

			else if (TargetNumber == CompareNumber)

			{

				nTempBalls++;

				break;

			}

		}

	}

	if ((nTempStrikes == nStrikes) && (nTempBalls == nBalls))

	{

		return 1;

	}

	else

	{

		return 0;

	}



}



int CalCandidates(int nLen, int * arrCandidates, int * pnMyChoice, int * pHowManyRealCandidates, int nStrikes, int nBalls, int fStartIdx)
{

	for (int i = 0; i < *pHowManyRealCandidates; i++)

	{

		if (*(arrCandidates + i) != 0)

		{

			if (CompareNums(*pnMyChoice, *(arrCandidates + i), nLen, nStrikes, nBalls))
			{

				//empty

			}
			else

			{

				*(arrCandidates + i) = 0;

			}

		}



	}
	if (s32_AnalysisView == 1)
	{
		int s32_NumPossbleCands = 0;
		for (int i = 0; i < *pHowManyRealCandidates; i++)
		{
			if (*(arrCandidates + i) != 0)
			{
				s32_NumPossbleCands++;
			}
		}
		printf("- �ĺ� ���(�� %d��)\n", s32_NumPossbleCands);
		for (int i = 0; i < *pHowManyRealCandidates; i++)
		{
			if (*(arrCandidates + i) != 0)
			{
				printf("%d ", *(arrCandidates + i));
			}
		}
		printf("\n\n");

	}
	return 1;
	/*for (int i = 0; i < *pHowManyRealCandidates; i++)

	{

	printf("%d ", *(arrCandidates + i));

	}*/

}



int main(void)

{

	int nLen = 0;

	int arrGuessNum[1000] = { 0 };

	int nRound = 1;

	int numCandidates = 1;

	int arrResultFlag[2] = { 0 }; //Strike, Ball ����

	int HowManyRealCandidates = 0;

	int nStrikes = 0, nBalls = 0;

	int nMyChoice = 0;

	int fStartIdx = 0;

	srand((unsigned int)time(NULL));



	printf("===============�µ����� �߱� ����!!!===============\n���۱��� ���µ����� ����. ���ܹ��� ����.\n\n\n");





	nRes = DecideMyNum(&nLen);

	if (s32_DebugMode == 1)
	{
		printf("��ǻ���� ����: %d\n", nRes);
	}

	for (int i = 1; i < nLen + 1; i++)

	{

		numCandidates = (11 - i)*numCandidates;

	}



	int *arrCandidates = (int*)malloc(sizeof(int)*numCandidates);



	//printf("�µ��� ����: %d\n", nRes);

	InitCandidates(nLen, arrCandidates, &HowManyRealCandidates);


	while (1)

	{

		printf("<���� %d>\n", nRound);
		if (s32_DebugMode == 0)
		{

			GetGuessNum(arrGuessNum, nRound, nLen);

			if (ShowGuessResult(nRes, arrGuessNum[nRound], nLen, arrResultFlag) == 1)

			{

				return 0;

			}
		}



		if (ShowGuessNumber(arrCandidates, &HowManyRealCandidates, &nMyChoice, &fStartIdx) == -1)
		{

			return 0;

		}
		if (s32_DebugMode == 0)
		{
			GetGuessResult(arrCandidates, &HowManyRealCandidates, &nStrikes, &nBalls);

		}
		else
		{
			if (ShowGuessResult(nRes, nMyChoice, nLen, arrResultFlag) == 1)
			{
				return 0;
			}
			nStrikes = arrResultFlag[0];
			nBalls = arrResultFlag[1];
		}
		CalCandidates(nLen, arrCandidates, &nMyChoice, &HowManyRealCandidates, nStrikes, nBalls, fStartIdx);

		nRound++;

	}





	free(arrCandidates);



	return 0;

}