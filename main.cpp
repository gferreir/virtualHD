#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main(int argc, char *argv[])
{
	char str[100];
	char HD[100];
	char createHd[9] = "createhd";
	
	
	char arquivo[100];
	char nome[100];
	char create[7] = "create";
	cout << "# ";
	gets(str);
	
	int i =0, j = 0;

	while(str[i] == createHd[i] && str[i] !='\0'){
		i++;
		if(str[i] != createHd[i]){
			printf("Errado");
			return 0;
		}
	}
	
	
	
	if(i==8){
		i++;
		while(str[i] !='\0'){
			HD[j]=str[i];
			
			if(str[i + 1] == '\0'){
				HD[j+1] = str[i+1];
			}
			i++;
			j++;
			
		}
		i=0;
		j=0;
	}
	
	cout << "# " << HD << "> ";
	gets(arquivo);

	while(arquivo[i] == create[i] && arquivo[i] !='\0'){
		i++;
	}

	if(i==8){
		i++;
		while(arquivo[i] !='\0'){
			nome[j]=arquivo[i];

			if(arquivo[i + 1] == '\0'){
				nome[j+1] = arquivo[i+1];
			}
			i++;
			j++;

		}
		i=0;
		j=0;
	}


	ofstream file;
	file.open(HD);
	file.close();

	system("pause");
	return 0;
}
