#include<stdio.h>
#include<conio.h>
int main(){
	char str[100];
	int i, words = 0 , newline = 0, characters = 0;
	printf("Enter a Line of Text:");
	scanf("%[^~]s",str);
	for(i=0;str[i]!='\0';i++){
		if(str[i]==' '){
			words++;
		}
		else if(str[i]=='\n'){
			words++;
			newline++;
		}
		else{
			characters++;
		}
	}
	if(characters > 0){
		words++;
		newline++;
	}
	printf("%s%d%s%d%s%d","\nWords: ",words,"\nLines: ",newline-1,"\nCharacters: ",characters);
}
