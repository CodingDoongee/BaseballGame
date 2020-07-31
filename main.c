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



	printf("몇 자리 숫자로 게임을 하겠습니까?(2~7자리)\n");

	scanf_s("%d", plength);



	while (*plength <= 0 || *plength > 7)

	{

		printf("유효한 자리수를 입력해주세요: \n");

		scanf_s("%d", plength);

	}

	printf("관전모드로 게임을 관찰하겠습니까?: \n");
	scanf_s("%d", &s32_DebugMode);

	if (s32_DebugMode == 0)
	{
		printf("게임 시 후보들을 보시겠습니까?: \n");
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
				// 난수를하나생성
				a[i] = rand() % 10;

				// 이미있는값인지확인하기위해플래그설정
				bFound = 0;

				// 같은값이있는지확인한다
				for (int j = 0; j < i; ++j)
				{
					// 같은값이있으면
					if (a[j] == a[i])
					{
						// 같은값이이미있음
						bFound = 1;
						break;
					}
				}
				// 같은값이없으면while문탈출
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
	// 셋 중 가장 맞추기 어려운 숫자를 고름


	return nResult;

}



int GetGuessNum(int * arrGuessNum, int nRound, int length)

{

	while (1)

	{

		printf("추측한 %d자리 숫자를 입력해주세요: \n", length);

		scanf_s("%d", &arrGuessNum[nRound]);



		if (((arrGuessNum[nRound]) > (int)(pow(10, length - 2))) && ((arrGuessNum[nRound]) < (int)(pow(10, length))))

		{

			break;

		}

		printf("유효한 자릿수가 아닙니다\n");

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



	printf("스트라이크: %d\n", arrResultFlag[0]);

	printf("볼: %d\n\n", arrResultFlag[1]);

	if (arrResultFlag[0] == nLen)
	{

		printf("당신이 게임에 승리했습니다!!! 축하합니다!!\n");

		printf("(1000초 후 종료합니다...)\n");
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


	// 후보 선택 모듈
	if (s32_NumOfPossibleCands == 1)
	{
		Listidx = 0;

	}
	else if (s32_NumOfPossibleCands == 0)
	{
		printf("후보가 없음!!\n");
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
			printf("당신의 최종 정답은 이것입니다: %d\n", *pnMyChoice);
			printf("제 정답은 %d 입니다\n", nRes);
			printf("(1000초 후 종료합니다...)\n");

			Sleep(1000000);

			return -1;

		}
		else
		{

			printf("태동이가 제시할 숫자는 이것입니다: %d\n", *pnMyChoice);
			return 1;
		}
	}
	else
	{

		printf("잘못된 정보를 주셔서 게임을 종료합니다...\n");
		printf("제 정답은 %d 입니다\n", nRes);
		printf("(1000초 후 종료합니다...)\n");

		Sleep(1000000);


		return -1;

	}



}



int GetGuessResult(int * arrCandidates, int * pHowManyRealCandidates, int * pnStrikes, int * pnBalls)

{

	char fSure = 'N';

	while ((fSure == 'N') || (fSure == 'n'))

	{

		printf("스트라이크가 몇개인가요?: ");

		scanf_s("%d", pnStrikes);

		printf("볼이 몇개인가요?: ");

		scanf_s("%d", pnBalls);

		printf("확실히 입력했나요?(Y/N) : ");

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
		printf("- 후보 목록(총 %d개)\n", s32_NumPossbleCands);
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

	int arrResultFlag[2] = { 0 }; //Strike, Ball 순서

	int HowManyRealCandidates = 0;

	int nStrikes = 0, nBalls = 0;

	int nMyChoice = 0;

	int fStartIdx = 0;

	srand((unsigned int)time(NULL));



	printf("===============태동이의 야구 게임!!!===============\n저작권은 오태동에게 있음. 무단배포 금지.\n\n\n");





	nRes = DecideMyNum(&nLen);

	if (s32_DebugMode == 1)
	{
		printf("컴퓨터의 정답: %d\n", nRes);
	}

	for (int i = 1; i < nLen + 1; i++)

	{

		numCandidates = (11 - i)*numCandidates;

	}



	int *arrCandidates = (int*)malloc(sizeof(int)*numCandidates);



	//printf("태동이 숫자: %d\n", nRes);

	InitCandidates(nLen, arrCandidates, &HowManyRealCandidates);


	while (1)

	{

		printf("<라운드 %d>\n", nRound);
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