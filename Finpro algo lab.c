#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Albertus Giovanni Prasetyo
// Christoper Julio
// Valentino Marcell

struct siswa{
	long long int ID;
	char nama[50];
	char jenisKursus[15];
	float nilaiKuis;
	float nilaiTugas;
	float nilaiUjian;
	float nilaiAkhirKursus;
	char gradeAkhir;
};

void menuSort()
{
		printf ("===============Menu Sorting===============\n");
		printf ("1. Sort By ID (Ascending)\n");
		printf ("2. Sort By ID (Descending)\n");
		printf ("3. Sort By Nilai Akhir Kursus (Ascending)\n");
		printf ("4. Sort By Nilai Akhir Kursus (Descending)\n");
		printf ("----------------  Choose  ----------------\n");
		printf ("-> ");
}

void entry(){
	struct siswa siswa;
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "a");
	printf ("==== Input Data Siswa ====");
	printf ("\nMasukkan ID: ");
	scanf ("%lld", &siswa.ID);
	getchar();
	printf ("Masukkan Nama: ");
	scanf ("%[^\n]", &siswa.nama);
	getchar();
	printf ("Masukkan Jenis Kursus (Beginner/Intermediate/Advanced): ");
	scanf ("%s", &siswa.jenisKursus);
	getchar();
	printf ("Nilai Quiz: ");
	scanf ("%f", &siswa.nilaiKuis);
	printf ("Nilai Tugas: ");
	scanf ("%f", &siswa.nilaiTugas);
	printf ("Nilai Ujian: ");
	scanf ("%f", &siswa.nilaiUjian);
	siswa.nilaiAkhirKursus = (siswa.nilaiKuis * 0.3) + (siswa.nilaiTugas * 0.3) + (siswa.nilaiUjian * 0.4);
	if(siswa.nilaiAkhirKursus >= 85){
		strcpy(&siswa.gradeAkhir, "A");
	} else if(siswa.nilaiAkhirKursus >= 70){
		strcpy(&siswa.gradeAkhir, "B");
	} else if(siswa.nilaiAkhirKursus >= 60){
		strcpy(&siswa.gradeAkhir, "C");
	} else if(siswa.nilaiAkhirKursus >= 50){
		strcpy(&siswa.gradeAkhir, "D");
	} else if(siswa.nilaiAkhirKursus < 50){
		strcpy(&siswa.gradeAkhir, "E");
	} 
	fprintf (ptr, "%lld;%s;%s;%.2f;%.2f;%.2f;%.2f;%s\n", siswa.ID, siswa.nama, siswa.jenisKursus, siswa.nilaiKuis, siswa.nilaiTugas, siswa.nilaiUjian, siswa.nilaiAkhirKursus, &siswa.gradeAkhir);
	printf ("Data Successfully Added\n");
	fclose (ptr);
}

int read(struct siswa siswa[100]){
	int count = 0;
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	while (fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &siswa[count].ID, &siswa[count].nama, &siswa[count].jenisKursus, &siswa[count].nilaiKuis, &siswa[count].nilaiTugas, &siswa[count].nilaiUjian, &siswa[count].nilaiAkhirKursus, &siswa[count].gradeAkhir) != EOF)
	{
		count++;
	}
	fclose(ptr);
	return count;
}

void display(struct siswa siswa[100]){
	int count = 0;
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	printf ("==================================================================================================================================\n");
	printf ("| ID	     | Nama\t\t   | Jenis Kursus  \t| Nilai Kuis    | Nilai Tugas   | Nilai Ujian   | Nilai Akhir  | Grade  |\n");
	printf ("==================================================================================================================================\n");
	while (fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &siswa[count].ID, &siswa[count].nama, &siswa[count].jenisKursus, &siswa[count].nilaiKuis, &siswa[count].nilaiTugas, &siswa[count].nilaiUjian, &siswa[count].nilaiAkhirKursus, &siswa[count].gradeAkhir) != EOF)
	{
		printf("| %lld | %-20s| %-13s\t| %5.2f \t| %5.2f \t| %5.2f \t| %5.2f \t| %s \t|\n", siswa[count].ID, siswa[count].nama, siswa[count].jenisKursus, siswa[count].nilaiKuis, siswa[count].nilaiTugas, siswa[count].nilaiUjian, siswa[count].nilaiAkhirKursus, &siswa[count].gradeAkhir);
		printf ("----------------------------------------------------------------------------------------------------------------------------------\n");
		count++;
	}
	printf("\n");
	fclose(ptr);
}

void sortByNAKA()
{
	struct siswa arrOfSiswa[100];
	struct siswa temp;
	int i = 0;
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	while(fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &arrOfSiswa[i].ID, &arrOfSiswa[i].nama, &arrOfSiswa[i].jenisKursus, &arrOfSiswa[i].nilaiKuis, &arrOfSiswa[i].nilaiTugas, &arrOfSiswa[i].nilaiUjian, &arrOfSiswa[i].nilaiAkhirKursus, &arrOfSiswa[i].gradeAkhir) != EOF)
	{
		i++;
	}
	fclose(ptr);
	for (int j = 0; j < i-1; j++){
        for (int k = 0; k < i - j-1; k++){
            if (arrOfSiswa[k].nilaiAkhirKursus < arrOfSiswa[k + 1].nilaiAkhirKursus){
                temp = arrOfSiswa[k];
                arrOfSiswa[k]=arrOfSiswa[k+1];
                arrOfSiswa[k+1]=temp;
			}
		}
	}
	printf ("==================================================================================================================================\n");
	printf ("| ID	     | Nama\t\t   | Jenis Kursus  \t| Nilai Kuis    | Nilai Tugas   | Nilai Ujian   | Nilai Akhir  | Grade  |\n");
	printf ("==================================================================================================================================\n");
	for(int j=0; j<i; j++){
		printf("| %lld | %-20s| %-13s\t| %5.2f \t| %5.2f \t| %5.2f \t| %5.2f \t| %s \t|\n",arrOfSiswa[j].ID,arrOfSiswa[j].nama,arrOfSiswa[j].jenisKursus,arrOfSiswa[j].nilaiKuis,arrOfSiswa[j].nilaiTugas,arrOfSiswa[j].nilaiUjian,arrOfSiswa[j].nilaiAkhirKursus,&arrOfSiswa[j].gradeAkhir);
		printf ("----------------------------------------------------------------------------------------------------------------------------------\n");
	}
	ptr = fopen("DataSiswa.txt","w");
	for(int j=0; j<i; j++){
		fprintf(ptr,"%lld;%s;%s;%.2f;%.2f;%.2f;%.2f;%s\n", arrOfSiswa[j].ID,arrOfSiswa[j].nama,arrOfSiswa[j].jenisKursus,arrOfSiswa[j].nilaiKuis,arrOfSiswa[j].nilaiTugas,arrOfSiswa[j].nilaiUjian, arrOfSiswa[j].nilaiAkhirKursus, &arrOfSiswa[j].gradeAkhir);
	}
	printf("\n");
	fclose(ptr);
}

void sortByNAKD()
{
	struct siswa arrOfSiswa[100];
	struct siswa temp;
	int i = 0;
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	while(fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &arrOfSiswa[i].ID, &arrOfSiswa[i].nama, &arrOfSiswa[i].jenisKursus, &arrOfSiswa[i].nilaiKuis, &arrOfSiswa[i].nilaiTugas, &arrOfSiswa[i].nilaiUjian, &arrOfSiswa[i].nilaiAkhirKursus, &arrOfSiswa[i].gradeAkhir) != EOF)
	{
		i++;
	}
	fclose(ptr);
	for (int j = 0; j < i-1; j++){
        for (int k = 0; k < i - j-1; k++){
            if (arrOfSiswa[k].nilaiAkhirKursus > arrOfSiswa[k + 1].nilaiAkhirKursus){
                temp = arrOfSiswa[k];
                arrOfSiswa[k]=arrOfSiswa[k+1];
                arrOfSiswa[k+1]=temp;
			}
		}
	}
	printf ("==================================================================================================================================\n");
	printf ("| ID	     | Nama\t\t   | Jenis Kursus  \t| Nilai Kuis    | Nilai Tugas   | Nilai Ujian   | Nilai Akhir  | Grade  |\n");
	printf ("==================================================================================================================================\n");
	for(int j=0; j<i; j++){
		printf("| %lld | %-20s| %-13s\t| %5.2f \t| %5.2f \t| %5.2f \t| %5.2f \t| %s \t|\n",arrOfSiswa[j].ID,arrOfSiswa[j].nama,arrOfSiswa[j].jenisKursus,arrOfSiswa[j].nilaiKuis,arrOfSiswa[j].nilaiTugas,arrOfSiswa[j].nilaiUjian,arrOfSiswa[j].nilaiAkhirKursus,&arrOfSiswa[j].gradeAkhir);
		printf ("----------------------------------------------------------------------------------------------------------------------------------\n");
	}
	ptr = fopen("DataSiswa.txt","w");
	for(int j=0; j<i; j++){
		fprintf(ptr,"%lld;%s;%s;%.2f;%.2f;%.2f;%.2f;%s\n", arrOfSiswa[j].ID,arrOfSiswa[j].nama,arrOfSiswa[j].jenisKursus,arrOfSiswa[j].nilaiKuis,arrOfSiswa[j].nilaiTugas,arrOfSiswa[j].nilaiUjian, arrOfSiswa[j].nilaiAkhirKursus, &arrOfSiswa[j].gradeAkhir);
	}
	printf("\n");
	fclose(ptr);
}

void sortByIdA()
{
	struct siswa arrOfSiswa[100];
	struct siswa temp;
	int i = 0;
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	while(fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &arrOfSiswa[i].ID, &arrOfSiswa[i].nama, &arrOfSiswa[i].jenisKursus, &arrOfSiswa[i].nilaiKuis, &arrOfSiswa[i].nilaiTugas, &arrOfSiswa[i].nilaiUjian, &arrOfSiswa[i].nilaiAkhirKursus, &arrOfSiswa[i].gradeAkhir) != EOF)
	{
		i++;
	}
	fclose(ptr);
	for (int j = 0; j < i-1; j++){
        for (int k = 0; k < i - j-1; k++){
            if (arrOfSiswa[k].ID < arrOfSiswa[k + 1].ID){
                temp = arrOfSiswa[k];
                arrOfSiswa[k]=arrOfSiswa[k+1];
                arrOfSiswa[k+1]=temp;
			}
		}
	}
	printf ("==================================================================================================================================\n");
	printf ("| ID	     | Nama\t\t   | Jenis Kursus  \t| Nilai Kuis    | Nilai Tugas   | Nilai Ujian   | Nilai Akhir  | Grade  |\n");
	printf ("==================================================================================================================================\n");
	for(int j=0; j<i; j++){
		printf("| %lld | %-20s| %-13s\t| %5.2f \t| %5.2f \t| %5.2f \t| %5.2f \t| %s \t|\n",arrOfSiswa[j].ID,arrOfSiswa[j].nama,arrOfSiswa[j].jenisKursus,arrOfSiswa[j].nilaiKuis,arrOfSiswa[j].nilaiTugas,arrOfSiswa[j].nilaiUjian,arrOfSiswa[j].nilaiAkhirKursus,&arrOfSiswa[j].gradeAkhir);
		printf ("----------------------------------------------------------------------------------------------------------------------------------\n");
	}
	ptr = fopen("DataSiswa.txt","w");
	for(int j=0; j<i; j++){
		fprintf(ptr,"%lld;%s;%s;%.2f;%.2f;%.2f;%.2f;%s\n", arrOfSiswa[j].ID,arrOfSiswa[j].nama,arrOfSiswa[j].jenisKursus,arrOfSiswa[j].nilaiKuis,arrOfSiswa[j].nilaiTugas,arrOfSiswa[j].nilaiUjian, arrOfSiswa[j].nilaiAkhirKursus, &arrOfSiswa[j].gradeAkhir);
	}
	printf("\n");
	fclose(ptr);
}

void sortByIdD()
{
	struct siswa arrOfSiswa[100];
	struct siswa temp;
	int i = 0;
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	while(fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &arrOfSiswa[i].ID, &arrOfSiswa[i].nama, &arrOfSiswa[i].jenisKursus, &arrOfSiswa[i].nilaiKuis, &arrOfSiswa[i].nilaiTugas, &arrOfSiswa[i].nilaiUjian, &arrOfSiswa[i].nilaiAkhirKursus, &arrOfSiswa[i].gradeAkhir) != EOF)
	{
		i++;
	}
	fclose(ptr);
	for (int j = 0; j < i-1; j++){
        for (int k = 0; k < i - j-1; k++){
            if (arrOfSiswa[k].ID > arrOfSiswa[k + 1].ID){
                temp = arrOfSiswa[k];
                arrOfSiswa[k]=arrOfSiswa[k+1];
                arrOfSiswa[k+1]=temp;
			}
		}
	}
	printf ("==================================================================================================================================\n");
	printf ("| ID	     | Nama\t\t   | Jenis Kursus  \t| Nilai Kuis    | Nilai Tugas   | Nilai Ujian   | Nilai Akhir  | Grade  |\n");
	printf ("==================================================================================================================================\n");
	for(int j=0; j<i; j++){
		printf("| %lld | %-20s| %-13s\t| %5.2f \t| %5.2f \t| %5.2f \t| %5.2f \t| %s \t|\n",arrOfSiswa[j].ID,arrOfSiswa[j].nama,arrOfSiswa[j].jenisKursus,arrOfSiswa[j].nilaiKuis,arrOfSiswa[j].nilaiTugas,arrOfSiswa[j].nilaiUjian,arrOfSiswa[j].nilaiAkhirKursus,&arrOfSiswa[j].gradeAkhir);
		printf ("----------------------------------------------------------------------------------------------------------------------------------\n");
	}
	ptr = fopen("DataSiswa.txt","w");
	for(int j=0; j<i; j++){
		fprintf(ptr,"%lld;%s;%s;%.2f;%.2f;%.2f;%.2f;%s\n", arrOfSiswa[j].ID,arrOfSiswa[j].nama,arrOfSiswa[j].jenisKursus,arrOfSiswa[j].nilaiKuis,arrOfSiswa[j].nilaiTugas,arrOfSiswa[j].nilaiUjian, arrOfSiswa[j].nilaiAkhirKursus, &arrOfSiswa[j].gradeAkhir);
	}
	printf("\n");
	fclose(ptr);
}

void searchByID()
{
	struct siswa arrOfSiswa[100];
	int i = 0;
	long long int keyID;
	printf("Insert ID To Search : ");
	scanf("%lld", &keyID);
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	while(fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &arrOfSiswa[i].ID, &arrOfSiswa[i].nama, &arrOfSiswa[i].jenisKursus, &arrOfSiswa[i].nilaiKuis, &arrOfSiswa[i].nilaiTugas, &arrOfSiswa[i].nilaiUjian, &arrOfSiswa[i].nilaiAkhirKursus, &arrOfSiswa[i].gradeAkhir) != EOF)
	{
		i++;
	}
	fclose(ptr);
	int k = 0;
	printf ("==================================================================================================================================\n");
	printf ("| ID	     | Nama\t\t   | Jenis Kursus  \t| Nilai Kuis    | Nilai Tugas   | Nilai Ujian   | Nilai Akhir  | Grade  |\n");
	printf ("==================================================================================================================================\n");
    for (k = 0; k < i ; k++){
		if(keyID == arrOfSiswa[k].ID){
			printf("| %lld | %-20s| %-13s\t| %5.2f \t| %5.2f \t| %5.2f \t| %5.2f \t| %s \t|\n", arrOfSiswa[k].ID, arrOfSiswa[k].nama, arrOfSiswa[k].jenisKursus, arrOfSiswa[k].nilaiKuis,arrOfSiswa[k].nilaiTugas,arrOfSiswa[k].nilaiUjian,arrOfSiswa[k].nilaiAkhirKursus,&arrOfSiswa[k].gradeAkhir);
			printf ("----------------------------------------------------------------------------------------------------------------------------------\n");
			break;
		} else{
			printf("ID Not Found\n");
			break;
		}
	}
	printf("\n");
}

void searchByGrade()
{
	struct siswa arrOfSiswa[100];
	int i = 0;
	char keyGrade[20];
	printf("Insert Grade To Search : ");
	scanf("%s", keyGrade);
	getchar();
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	while(fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &arrOfSiswa[i].ID, &arrOfSiswa[i].nama, &arrOfSiswa[i].jenisKursus, &arrOfSiswa[i].nilaiKuis, &arrOfSiswa[i].nilaiTugas, &arrOfSiswa[i].nilaiUjian, &arrOfSiswa[i].nilaiAkhirKursus, &arrOfSiswa[i].gradeAkhir) != EOF)
	{
		i++;
	}
	fclose(ptr);
	int k = 0;
	printf ("==================================================================================================================================\n");
	printf ("| ID	     | Nama\t\t   | Jenis Kursus  \t| Nilai Kuis    | Nilai Tugas   | Nilai Ujian   | Nilai Akhir  | Grade  |\n");
	printf ("==================================================================================================================================\n");
    for (k = 0; k < i ; k++){
		if(strcmp(&arrOfSiswa[k].gradeAkhir, keyGrade) == 0){
			printf("| %lld | %-20s| %-13s\t| %5.2f \t| %5.2f \t| %5.2f \t| %5.2f \t| %s \t|\n", arrOfSiswa[k].ID, arrOfSiswa[k].nama, arrOfSiswa[k].jenisKursus, arrOfSiswa[k].nilaiKuis,arrOfSiswa[k].nilaiTugas,arrOfSiswa[k].nilaiUjian,arrOfSiswa[k].nilaiAkhirKursus,&arrOfSiswa[k].gradeAkhir);
			printf ("----------------------------------------------------------------------------------------------------------------------------------\n");
		}
	}
	printf("\n");
}

void searchByJK()
{
	struct siswa arrOfSiswa[100];
	int i = 0;
	char keyJK[20];
	printf("Insert Jenis Kursus To Search : ");
	scanf("%s", keyJK);
	getchar();
	FILE *ptr;
	ptr = fopen ("DataSiswa.txt", "r");
	while(fscanf(ptr, "%lld;%[^\';'];%[^\';'];%f;%f;%f;%f;%s\n", &arrOfSiswa[i].ID, &arrOfSiswa[i].nama, &arrOfSiswa[i].jenisKursus, &arrOfSiswa[i].nilaiKuis, &arrOfSiswa[i].nilaiTugas, &arrOfSiswa[i].nilaiUjian, &arrOfSiswa[i].nilaiAkhirKursus, &arrOfSiswa[i].gradeAkhir) != EOF)
	{
		i++;
	}
	fclose(ptr);
	int k = 0;
	printf ("==================================================================================================================================\n");
	printf ("| ID	     | Nama\t\t   | Jenis Kursus  \t| Nilai Kuis    | Nilai Tugas   | Nilai Ujian   | Nilai Akhir  | Grade  |\n");
	printf ("==================================================================================================================================\n");
    for (k = 0; k < i ; k++){
		if(strcmp(&arrOfSiswa[k].jenisKursus, keyJK) == 0){
			printf("| %lld | %-20s| %-13s\t| %5.2f \t| %5.2f \t| %5.2f \t| %5.2f \t| %s \t|\n", arrOfSiswa[k].ID, arrOfSiswa[k].nama, arrOfSiswa[k].jenisKursus, arrOfSiswa[k].nilaiKuis,arrOfSiswa[k].nilaiTugas,arrOfSiswa[k].nilaiUjian,arrOfSiswa[k].nilaiAkhirKursus,&arrOfSiswa[k].gradeAkhir);
			printf ("----------------------------------------------------------------------------------------------------------------------------------\n");
		}
	}
	printf("\n");
}

int main(){
	struct siswa siswa[100];
	int count = 0;
	int menuSelect, menuSelectSort, menuSelectSearch;
	do
	{
		int count = 0;
		printf ("======	Welcome ======\n");
		printf ("	-Menu- \n");
		printf ("1. Add Data\n");
		printf ("2. Read Data\n");
		printf ("3. Sorting Data\n");
		printf ("4. Search Data\n");
		printf ("0. Exit\n");
		printf ("------	Choose  ------\n");
		printf ("-> ");
		scanf ("%d", &menuSelect);
		switch (menuSelect){
			case 1:
				system ("cls");
				entry();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				display(siswa);
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				printf ("================ Sorting =================\n");
				printf ("1. Sort By ID (Ascending)\n");
				printf ("2. Sort By ID (Descending)\n");
				printf ("3. Sort By Nilai Akhir Kursus (Ascending)\n");
				printf ("4. Sort By Nilai Akhir Kursus (Descending)\n");
				printf ("----------------  Choose  ----------------\n");
				printf ("-> ");
				scanf ("%d", &menuSelectSort);
				if(menuSelectSort == 1){
					system("cls");
					sortByIdA();
					system("pause");
					system("cls");
					break;
				} else if(menuSelectSort == 2){
					system("cls");
					sortByIdD();
					system("pause");
					system("cls");
					break;
				} else if(menuSelectSort == 3){
					system("cls");
					sortByNAKA();
					system("pause");
					system("cls");
					break;
				} else if(menuSelectSort == 4){
					system("cls");
					sortByNAKD();
					system("pause");
					system("cls");
					break;
				}
			case 4:
				system("cls");
				printf ("================ Seaching =================\n");
				printf ("1. Search By ID \n");
				printf ("2. Search By Grade \n");
				printf ("3. Search By Jenis Kursus \n");
//				printf ("4. Sort By Nilai Akhir Kursus (Descending)\n");
				printf ("----------------  Choose  ----------------\n");
				printf ("-> ");
				scanf ("%d", &menuSelectSearch);
				if(menuSelectSearch == 1){
					system("cls");
					searchByID();
					system("pause");
					system("cls");
					break;
				} else if(menuSelectSearch == 2){
					system("cls");
					searchByGrade();
					system("pause");
					system("cls");
					break;
				} else if(menuSelectSearch == 3){
					system("cls");
					searchByJK();
					system("pause");
					system("cls");
					break;
				}
			case 0:
				break;
			default:
				printf ("Invalid Input!\n");	
            	system("pause");
          		system("cls");
         		break;
		}
	}while (menuSelect != 0);
	system("cls");
	printf ("Thank you for using our service\n");
	return 0;
	
}
