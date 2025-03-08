#include <stdio.h>
#include <string.h>
#include "student.h"
#include "library.h"
#include "book.h"

// Function to add a book in library, takes library structure, book structure and adding index as arguments
void add_book(struct library *lib)
{
	struct book b;
	FILE* myfile = fopen("bookdata.dat","w");
	while (1) {
		printf("Enter book number : \n");
		char no[100];
		int ss = 0;
		gets(no);
		printf("\n");
		
		for (int i = 0; i < strlen(no); i++) {
			ss = ss*10 + (no[i] - '0');
		}
		b.book_no = ss;
		printf("Enter book name : \n");
		gets(b.book_name);
		printf("\n");
		if (strcmp(b.book_name,"done") == 0) break;
		printf("Enter author name : \n");
		gets(b.author_name);
		printf("\n");
		printf("Enter price : \n");
		char price[100];
		gets(price);
		printf("\n");
		int s = 0;
		for (int i = 0; i < strlen(price); i++) {
			s = s*10 + (price[i] - '0');
		}
		b.price = s;
		fwrite(&b, sizeof(struct book ), 1, myfile);

	}
	fclose(myfile);
	FILE* o = fopen("bookdata.dat", "r");
	if (o == NULL) {
		printf("counl open the filea\n");
	}
	
	int add = 0;
	while (fread(&b, sizeof(struct book),1,o)){

		strcpy(lib->record[add], b.book_name);

		add++;
	}
	fclose(o);
	// printf("%s\n",lib->record[add-1]);

	for (int i = 0; i < add; i++) {
		printf("%s\n", lib->record[i]);
	}
}

// Function to show book information, takes book structure as argument
void show_info(struct book *b)
{
	printf("Book number : %i\n", b->book_no);
	printf("Book name : %s\n", b->book_name);
	printf("Auther name : %s\n", b->author_name);
	printf("Price : %i\n", b->price);

}

// Function that shows author name corresponding to the book title
void book_of(struct book book_list[100], char *author)
{

	int sss = strcmp(book_list[0].author_name, author);
	for(int i = 0; i < 100; i++) {
		// sss stores the comparison result of author name of all books
		// (in each iteration ) to given author name
		sss = strcmp(book_list[i].author_name, author);
		
		// if comparison result is 0, that means we found a book, print its name
		if (sss == 0) {
			char name[100];
			strcpy(name,book_list[i].book_name);
			printf("%s\n", name);
		}

	}
}

// Functions that checks if the book is available or has already been issued
void is_book_available(struct library *lib, struct book b)
{
	int flag = 0;  // 0 if book not found/issued, 1 when book is available
	for (int i = 0; i < 100; i++){
		if (strcmp(lib->record[i],b.book_name) == 0) {
			flag = 1;  // If book was in library at some point then set flag to 1
		}

		// If book is already issued then set flag 0 and then break the loop
		if (strcmp(lib->issue_book_name[i], b.book_name) == 0) {
			printf("Sorry, the book %s is already issued by : %s\n",b.book_name, lib->issuer_name[i]);
			flag = 0;
			return;
		}
	}
	// If flag is 1, then print that the book is available
	
	printf("Yes! The book %s is available in library", b.book_name);
	
}

// Function to issue a book in library, takes library structure, book structure, issuer name(student structure)
// And adding index as arguements.
void issue_book(struct library *lib, struct book b, struct student s, int adding_index)
{
	strcpy(lib->issuer_name[adding_index], s.name);
	strcpy(lib->issue_book_name[adding_index], b.book_name);

}
int main()
{
	// Testing above functions
	struct library lib; // Creating library
	
	// // Creating book structure array
	// struct book books[] { {1, "sherlock holmes", "Arthur Conan Doyle", 1000},
	//  {2, "Harry Potter", "J.K Rowling", 950},
	//  {1, "Fantastic Beasts", "J.K Rowling", 900} };

	// struct student student_list[] {
	// 	{"Harsh kumar", 16},
	// 	{"Danniel Rand", 10},
	// 	{"Matthew Murdock", 1}
	// };
	
	struct student students[100];
	struct student inp;
	FILE *inf, *out;
	
	out = fopen("stout.dat","w");
	// while (fread(&inp,sizeof(struct student),2,inf)) {
	// 	printf("%s %i\n", inp.name, inp.roll);
	// 	fwrite(&inp,sizeof(struct student),2,out);
	// 	if (fwrite != 0) {
	// 		printf("Contents written succesfully\n");
	// 	}
	// 	else{
	// 		printf("error while writing file\n");
	// 	}
	// }
	int roll[100];
	int radd = 0;
	
	// while (1) {
	// 	printf("Enter Name : ");
	// 	gets(inp.name);
	// 	printf("\n");
	// 	if (strcmp(inp.name, "done") == 0) {
	// 		break;
	// 	}
	// 	printf("Enter roll : ");

	// 	char roll[100];
	// 	gets(roll);
	// 	printf("\n");
	// 	int s = 0;
	// 	for (int i = 0; i < strlen(roll); i++) {
	// 		s = s*10 + (roll[i] - '0');
	// 	}
	// 	inp.roll = s;
	// 	fwrite(&inp,sizeof(struct student),1,out);
	// 	}
		
		
		
		
	
	int libadd = 0;
	FILE* libdata = fopen("libdata.dat","w");

	// while (1) {
	// 	printf("Enter book name : ");
	// 	gets(lib.record[libadd]);
	// 	printf("\n");
	// 	printf("%s\n", lib.record[libadd]);
	// 	if (strcmp(lib.record[libadd],"done") == 0){
	// 		printf("breaking1\n");
	// 		break;
	// 	}
		
	// 	fwrite(&lib, sizeof(struct library), 1, libdata);
	// 	libadd++;

	//  }
	
	fclose(out);
	fclose(libdata);
	inf = fopen("stout.dat", "r");
	
	// while(fread(&inp,sizeof(struct student),1,inf)) {
	// 	printf("Name = %s Roll = %i\n", inp.name, inp.roll);
	// }
	fclose(inf);

	FILE* libr = fopen("libdata.dat", "r");
	// while (fread(&lib,sizeof(struct library),1,libr)){
	// 	printf("%s", lib.record);
	// }
	fclose(libr);

	


	

	// Testing functions

	// ----------Adding books to library ---------//
	// add_book(&lib, books[0],0);
	// add_book(&lib, books[1],1);
	// add_book(&lib, books[2],2);
	// // -------------------------------------------//

	// // ----------Show info of first book -------- //
	// show_info(&books[0]);
	// // ------------------------------------------ //
	

	// // ----------Show books of J.K Rowling ----- //
	// char jkrowling[100] = "J.K Rowling";
	// book_of(books, jkrowling);
	// // ----------------------------------------- //

	// // ----------Issue book Sherlock Holmes------------------- //
	
	// issue_book(&lib,books[0], student_list[0], 0);
	// // ---------------------------------------- //

	// //Check if Sherlock Holmes and Harry Potter are available in library or not //
	// is_book_available(&lib, books[0]);
	// is_book_available(&lib, books[1]);
	// // ------------------------------------------------------------------------ //
	add_book(&lib);
	
}