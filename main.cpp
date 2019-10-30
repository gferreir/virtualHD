#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>


using namespace std;


//Declaração variaveis
ifstream filer; // abre arquivo em modo de leitura
ofstream filew; // abre aquivo em modo de escrita
char HD[100];  // nome do HD
char arquivo[16];// nome arquivo
int posicao=0; // posição disponivel para escreve conteudo do arquivo
char matriz[1024][32]; // HD
char conteudo[100];// conteudo arquivo
char comando[100];
char createHd[9] = "createhd";
char comandoArq[100];//comando cria arquivo
char create[7] = "create";
char excluir[7] = "remove";
char proximo[200];
char comandoDelete[100];
string nome;
char nomePasta[16]; //nome da pasta
char nomePastaNavegacao[16]; // nome da pasta para navegaÃ§Ã£o
char lista[20][16];
string pastas;
char nomeHd[20];
int temPasta=0;
bool *cd = new bool;
char tempPosHD[4];
char nomeFile[30];
char nomeFile2[30];
string linhaConteudo;
int posicaoConteudo=0;
char nomeComando[20];
string conteudoLinha;




//Declaração funções
int iguais(char v[], char d[]);
void verificaDisponibilidade();
void criaMatriz();
void criaHD(int i);
void criaArquivo(int j);
void leituraHD();
void nomeArquivo();
void nomeHD(int i);
string formataTxT(char* txt);
void listaPastasArquivos();
void confirmaDisponibilidadeP();
void criaPasta(int i);
int estadoComando=0;
void verificaDisponibilidadeArq();


void nomeHD(int i){
	int j=0;
	while(comando[i] !='\0'){
		HD[j]=comando[i];
		nomeHd[j]=comando[i];

		if(comando[i + 1] == '\0'){
			HD[j+1] = comando[i+1];
			nomeHd[j+1]=comando[i+1];
		}
		i++;
		j++;

	}



}

void nomeArq(int i){
	int j=0;
	while(comando[i] !='\0'){
		arquivo[j]=comando[i];

		if(comando[i + 1] == '\0'){
			arquivo[j+1] = comando[i+1];
		}
		i++;
		j++;

	}

}

void nomeArqDel(int i){
	int j=0;
	while(comando[i] !='\0'){
		arquivo[j]=comando[i];

		if(comando[i + 1] == '\0'){
			arquivo[j+1] = comando[i+1];
		}
		i++;
		j++;

	}
	cout<<arquivo;

}

void leituraHD(){
	int i=0;
	int j=0;
	filer.open(nome.c_str());

    for (i = 0; i < 1024; i++){
        for (j = 0; j < 32; j++){
	        filer >> matriz[i][j];

        }

    }

    filer.close();
}

void verificaDisponibilidade(){
    int i=0;
     for(i=21;i<40;i++){
	        if(matriz[i][0] =='0'){
				posicao = i;


		}

	}

}

void listaPastasArquivos(){
    leituraHD();
    char tempNomePasta[16];
    tempPosHD[0] = '0';
    tempPosHD[1] = '0';
    tempPosHD[2] = '0';
    tempPosHD[3] = '0';
    for(int i = 0; i < 20; i++){
        if(matriz[i][2] == '1'){
            for(int j = 16; j < 32; j++){
                if(matriz[i][j] != 0) {
                    tempNomePasta[j - 16] = matriz[i][j];
                }
            }
            if(iguais(nomePastaNavegacao, tempNomePasta)){
                stringstream strs;
                strs  << i;
                string temp_str = strs.str();
                if(strlen(temp_str.c_str()) == 1){
                    tempPosHD[2] = '0';
                    tempPosHD[3] = (char) temp_str.c_str()[0];
                }
                if(strlen(temp_str.c_str()) == 2){
                    tempPosHD[2] = (char) temp_str.c_str()[0];
                    tempPosHD[3] = (char) temp_str.c_str()[1];
                }
                temPasta++;
                break;
            }
        }
    }
    int k;
    for(k = 0; k < 20; k++){
        if(lista[k][0] == 0){
            break;
        }
    }
    for(int i = 0; i < 20; i++){
        if(matriz[i][4] == tempPosHD[0] && matriz[i][5] == tempPosHD[1] && matriz[i][6] == tempPosHD[2] && matriz[i][7] == tempPosHD[3]){
            for(int j = 16; j < 32; j++){
                if(matriz[i][j] != 0) {
                    lista[k][j - 16] = matriz[i][j];
                }
            }
        }
    }


}


void confirmaDisponibilidadeP(){
    leituraHD();
    for (int i = 0; i<=20; i++){
        if(matriz[i][0] == '0'){
            criaPasta(i);
            filew.open(nome.c_str());
		    for (int i = 0; i<1024; i++){
		        for (int j = 0; j< 33 ;j++){
		            if(j == 32){
		                filew << endl;
		            }
		            else{
		                filew << matriz[i][j];
		            }
		        }
		    }
		    filew.close();
            memset(nomePasta,'\0', 16);
            return;
        }
    }

}

int verificaPasta(){
    char tempNomePasta[16];
    for(int i = 0; i < 20; i++){
        if(matriz[i][2] == '1'){
            for(int j = 16; j < 32; j++){
                if(matriz[i][j] != 0) {
                    tempNomePasta[j - 16] = matriz[i][j];
                }
            }
            if(temPasta==0){
            	return -1;
			}
            else if(iguais(nomePastaNavegacao, tempNomePasta)){
                return i;
            }
        }
    }
    return -1;
}

int verificaArquivo(char typeArquivo[16]){
    char charNomeArquivo[16];
    for(int i = 0; i < 20; i++){
        if(matriz[i][2] == '0'){
            for(int j = 16; j < 32; j++){
                if(matriz[i][j] != 0) {
                    charNomeArquivo[j - 16] = matriz[i][j];
                }
            }
            if(iguais(typeArquivo, charNomeArquivo)){
                return i;
            }
        }
    }
    return -1;
}

int validaComando(char comandoCopy[16]){
    char charNomeArquivo[16];
    for(int i = 0; i < 20; i++){
        if(matriz[i][2] == '0'){
            for(int j = 16; j < 32; j++){
                if(matriz[i][j] != 0) {
                    charNomeArquivo[j - 16] = matriz[i][j];
                }
            }
            if(iguais(comandoCopy, charNomeArquivo)){
                return i;
            }
        }
    }
    return -1;
}

int retornaLinhaConteudo(){
	int i=0;
	char conteudoPosicao[2];
	memset(conteudoPosicao,'\0', 16);
	char linhaConteudo[2];
		for(int j=10;j<12;j++){
			conteudoPosicao[i]= matriz[posicaoConteudo][j];
			i++;
		}

	return atoi(conteudoPosicao);




}

int verificaMaisConteudo(){
	int pos = retornaLinhaConteudo();
	char novaPosicao[4];
	memset(novaPosicao,'\0', 16);
	int i=0;

    for(int j=4;j<8;j++){
    	if(matriz[pos][j]!='0'){
    		novaPosicao[i] = matriz[pos][j];
    		i++;
		}
	}
	return atoi(novaPosicao);

}

void exibeType(){
	char conteudoLinha[100];
	int posicaoInicial = retornaLinhaConteudo();
	int posicaoNova = verificaMaisConteudo();
	int count =0;
	for(int j=8;j<32;j++){
		if(matriz[posicaoInicial][j]!='-'){
			if(count !=20){
				cout<<matriz[posicaoInicial][j];
				count++;
			}else{
				count =0;
			}

		}

	}

	cout<<endl;
	for(int j=8;j<32;j++){
		if(matriz[posicaoInicial+1][j]!='-'){
			if(count !=20){
				cout<<matriz[posicaoInicial+1][j];
				count++;
			}else{
				count =0;
			}
		}

	}
	cout<<endl;






}

void recuperaConteudo(){
	int posicaoInicial = retornaLinhaConteudo();
	int posicaoNova = verificaMaisConteudo();
	int count =0;
	for(int j=8;j<32;j++){
		if(matriz[posicaoInicial][j]!='-'){
				conteudoLinha+=matriz[posicaoInicial][j];			
		}

	}
	for(int j=8;j<32;j++){
		if(matriz[posicaoInicial+1][j]!='-'){
				conteudoLinha+=matriz[posicaoInicial+1][j];		
		}

	}
	
	cout<<conteudoLinha<<endl;
}

void criaPasta(int i){
    int l;
    l = verificaPasta();
    l++;
    for (int k = 0; k < 32; k++){
        if ( k == 0){
            matriz[i][k] = '1';
        }
        else if ( k == 2){
            matriz[i][k] = '1';
        }
        else if ( k >= 4 & k <= 7){
            if(l !=0){
                tempPosHD[4];
                tempPosHD[0] = '0';
                tempPosHD[1] = '0';
                tempPosHD[2] = '0';
                tempPosHD[3] = '0';
                stringstream strs;
                strs  << l;
                string temp_str = strs.str();
                if(strlen(temp_str.c_str()) == 1){
                    tempPosHD[2] = '0';
                    tempPosHD[3] = (char) temp_str.c_str()[0];
                }
                if(strlen(temp_str.c_str()) == 2){
                    tempPosHD[2] = (char) temp_str.c_str()[0];
                    tempPosHD[3] = (char) temp_str.c_str()[1];
                }
                matriz[i][k] = tempPosHD[k-4];
            }
            else{
                matriz[i][k] = '0';
            }
        }
        else if ( k >= 8 & k <= 11){
            matriz[i][k] = '0';
        }
        else if ( k >= 12 & k <= 15){
            matriz[i][k] = '0';
        }
        else if ( k >= 16 & k <= 31){
            matriz[i][k] = nomePasta[k-16];
        }
    }
}

int iguais(char v[], char d[]){
    int c = 0;
    while(v[c] != 0 ){
        if(v[c] != d[c]){
            return 0;
        }
        c++;
    }
    return 1;
}
void criaMatriz(){
    for (int i = 0; i<1024; i++){
        for (int j = 0; j< 33 ;j++){
            if (j == 0 || (j == 1 && i>=0 && i<=19)){
                filew << "0";
            }
            else if(j == 1 && i>=20){
                filew << "1";
            }
            else if(j == 32){
                filew << endl;
            }
            else{
                filew << "-";
            }
        }
    }
}

string formataTxT(char* txt){
	string nomeHD = txt;
	nomeHD += ".txt";
	return nomeHD;

}

void criaHD(int i){
	nomeHD(i);
	nome = formataTxT(HD);
	filew.open(nome.c_str());
	criaMatriz();
	filew.close();


}

int * verificaDisponibilidadeConteudo(int n){
	int *disponiveis = new int[n];
	int m;
	int i;
	for(m = 0; m < n;m++){
	    for (i= 20; i<1024; i++){
            if(matriz[i][0] == '0'){
				disponiveis[m] = i;
				matriz[i][0] = '1';
            	break;
        	}
		}
    }
    return disponiveis;
}

void criaProximo(int i){
    stringstream strs;
    strs  << i;
    string temp_str = strs.str();
    if(strlen(temp_str.c_str()) == 1){
        proximo[0] = '0';
        proximo[1] = '0';
        proximo[2] = '0';
        proximo[3] = (char) temp_str.c_str()[0];
    }
    if(strlen(temp_str.c_str()) == 2){
        proximo[0] = '0';
        proximo[1] = '0';
        proximo[2] = (char) temp_str.c_str()[0];
        proximo[3] = (char) temp_str.c_str()[1];
    }
    if(strlen(temp_str.c_str()) == 3){
        proximo[0] = '0';
        proximo[1] = (char) temp_str.c_str()[0];
        proximo[2] = (char) temp_str.c_str()[1];
        proximo[3] = (char) temp_str.c_str()[2];
    }
    if(strlen(temp_str.c_str()) == 4){
        proximo[0] = (char) temp_str.c_str()[0];
        proximo[1] = (char) temp_str.c_str()[1];
        proximo[2] = (char) temp_str.c_str()[2];
        proximo[3] = (char) temp_str.c_str()[3];
    }
    return;
}

void listaArquivos(){
    char bloco[5];
    int linhasUsadas=0;
    int x=0;
    leituraHD();
    for(int i=0;i<20;i++){
		if(matriz[i][0] == '1'){
			linhasUsadas++;
		}
	}

	for(x=0;x<linhasUsadas;x++){

		for(int y=4;y<8;y++){
			bloco[0] = matriz[x][y];
			y++;
			bloco[1] = matriz[x][y];
			y++;
			bloco[2] = matriz[x][y];
			y++;
			bloco[3] = matriz[x][y];
		}
		 if(iguais(tempPosHD,bloco)){
			for(int j=16;j<31;j++){
					if(matriz[x][j]!='\0'){
					cout<<matriz[x][j];

				}

				}
				cout<<" ";
				for(int j=12;j<16;j++){
					if(matriz[x][j]!='0'){
					cout<<matriz[x][j];
					}
				}

				cout<<" bytes";
		cout<<endl;
		}

		else{
		*cd =false;
	}
}




}

void deleteArquivo(){
    leituraHD();
    cout << "# " << HD << "> ";
    char tempNomeArquivo[16];
    char tempPosConteudo[4];
    int posicaoConteudo = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 16; j < 32; j++){
            if(matriz[i][j] != 0) {
                tempNomeArquivo[j - 16] = matriz[i][j];
            }
        }
        if(iguais(arquivo, tempNomeArquivo)){
            matriz[i][0] = '0';
            for(int k = 8; k < 12; k++){
                tempPosConteudo[k - 8] = matriz[i][k];
            }
            posicaoConteudo = atoi(tempPosConteudo);
        }
    }
    matriz[posicaoConteudo][0] = '0';
    while ( posicaoConteudo != 0){
        matriz[posicaoConteudo][0] = '0';
	    for(int k = 4; k < 8; k++){
	        tempPosConteudo[k - 4] = matriz[posicaoConteudo][k];
	    }
	    posicaoConteudo = atoi(tempPosConteudo);
	}
   filew.open(nome.c_str());
    for (int i = 0; i<1024; i++){
        for (int j = 0; j< 33 ;j++){
            if(j == 32){
                filew << endl;
            }
            else{
                filew << matriz[i][j];
            }
        }
    }
    filew.close();
}

void escreveArquivo(int i){
    int tamanho = strlen(conteudo);
    int nLinhas = (tamanho/24) + 1;
    int *a;
    a = verificaDisponibilidadeConteudo(nLinhas);
    criaProximo(a[0]);
    stringstream strs;
    strs  << tamanho;
    string temp_str = strs.str();
    char tamanhoConteudo[4];
    if(strlen(temp_str.c_str()) == 1){
        tamanhoConteudo[0] = '0';
        tamanhoConteudo[1] = '0';
        tamanhoConteudo[2] = '0';
        tamanhoConteudo[3] = (char) temp_str.c_str()[0];
    }
    if(strlen(temp_str.c_str()) == 2){
        tamanhoConteudo[0] = '0';
        tamanhoConteudo[1] = '0';
        tamanhoConteudo[2] = (char) temp_str.c_str()[0];
        tamanhoConteudo[3] = (char) temp_str.c_str()[1];
    }
    if(strlen(temp_str.c_str()) == 3){
        tamanhoConteudo[0] = '0';
        tamanhoConteudo[1] = (char) temp_str.c_str()[0];
        tamanhoConteudo[2] = (char) temp_str.c_str()[1];
        tamanhoConteudo[3] = (char) temp_str.c_str()[2];
    }
    if(strlen(temp_str.c_str()) == 4){
        tamanhoConteudo[0] = (char) temp_str.c_str()[0];
        tamanhoConteudo[1] = (char) temp_str.c_str()[1];
        tamanhoConteudo[2] = (char) temp_str.c_str()[2];
        tamanhoConteudo[3] = (char) temp_str.c_str()[3];
    }

    int l;
    l = verificaPasta();
    l++;

    int atual = 0;

    for (int k = 0; k < 32; k++){
        if ( k == 0){
            matriz[i][k] = '1';
        }
        else if ( k == 2){
            matriz[i][k] = '0';
        }
        else if ( k >= 4 & k <= 7){
              if(l !=0){
				tempPosHD[0] = '0';
				tempPosHD[1] = '0';
                tempPosHD[2] = '0';
				tempPosHD[3] = '0';
                stringstream strs;
                strs  << l;
                string temp_str = strs.str();
                if(strlen(temp_str.c_str()) == 1){
                    tempPosHD[2] = '0';
                    tempPosHD[3] = (char) temp_str.c_str()[0];
                }
                if(strlen(temp_str.c_str()) == 2){
                    tempPosHD[2] = (char) temp_str.c_str()[0];
                    tempPosHD[3] = (char) temp_str.c_str()[1];
                }
                matriz[i][k] = tempPosHD[k-4];
            }
            else{
                matriz[i][k] = '0';
            }

        }
        else if ( k >= 8 & k <= 11){

            matriz[i][k] = proximo[k-8];

        }
        else if ( k >= 12 & k <= 15){
            matriz[i][k] = tamanhoConteudo[k-12];
        }
        else if ( k >= 16 & k <= 31){
            matriz[i][k] = arquivo[k-16];
        }
    }
      for (int j = 0; j <= (nLinhas - 1);j++){
		if(j != (nLinhas - 1)){
            criaProximo(a[(j+1)]);
		}
        for (int k = 0; k < 32; k++){
            if ( k >= 4 & k <= 7){
                if(j == (nLinhas-1) && j==0){
                    matriz[(a[j])][k] = proximo[k-4];
                }else if(j == (nLinhas-1) && j!=0){
                    matriz[(a[j])][k] = '0';
                }else if(j != (nLinhas-1) && j!=0){
                    matriz[(a[j])][k] = '0';
                }
                else{
                    matriz[(a[j])][k] = proximo[k-4];
                }
            }
           else if ( k >= 8 & k <= 31){
				if (conteudo[atual] != 0){
                	matriz[a[j]][k] = conteudo[atual];
                	atual++;
				}
            }
    	}
	}
}





void verificaDisponibilidadeArq(){
    for (int i = 0; i<=20; i++){
        if(matriz[i][0] == '0'){
            escreveArquivo(i);
            filew.open(nome.c_str());
		    for (int i = 0; i<1024; i++){
		        for (int j = 0; j< 33 ;j++){
		            if(j == 32){
		                filew << endl;
		            }
		            else{
		                filew << matriz[i][j];
		            }
		        }
		    }
		    filew.close();
            return;
        }
    }
}

void criaArquivo(int j){

	nomeArq(j);
	leituraHD();
	cout<<"Digite o conteudo do arquivo:"<<endl;
	gets(conteudo);
	fflush(stdin);
	verificaDisponibilidadeArq();
	memset(arquivo,'\0', 16);

}

void copiaArquivo(string nomeArquivo, string conteudoLinha){
	
    
	arquivo[nomeArquivo.size() + 1];
	strcpy(arquivo, nomeArquivo.c_str());
	cout<<arquivo<<endl;
	leituraHD();
	conteudo[conteudoLinha.size() + 1];
	strcpy(conteudo, conteudoLinha.c_str());
	cout<<conteudo<<endl;
	fflush(stdin);
	verificaDisponibilidadeArq();
	memset(arquivo,'\0', 16);
	memset(conteudo,'\0', 16);
	

}



int main(int argc, char *argv[])
{

	int i =0, j = 0;
	char fim[5] = "exit";

	*cd = false;

	while(true){
        int i;
	    int k = 0;
	     if(*cd == false){
	        string nomeDoComando = nomeHd;
	        string comandoComNome = "# " + nomeDoComando + pastas + "> ";
	        cout << comandoComNome;
	    }
	    else{
	        string nomeDoComando = nomeHd;
	        string nomeDaPasta = nomePastaNavegacao;
	        pastas = pastas +  "\\" + nomeDaPasta;
	        string comandoComNome = "# " + nomeDoComando + pastas + "> ";
	        cout << comandoComNome;
	    }
	    cin.getline(comando, sizeof(comando));
	    fflush(stdin);

	    if (iguais(createHd, comando)){
			int i=9;
			criaHD(i);
		    criaMatriz();
		    *cd = false;
	    }
	    else if (iguais(create, comando)){
	        int j=7;
		    criaArquivo(j);
		    *cd =false;
	    }
	    else if(iguais(excluir, comando)){
	        int j=7;
	        nomeArq(j);
	        deleteArquivo();
	        *cd = false;
	    }
	    else if(iguais("dir", comando)){
            listaArquivos();

		}
	    else if(iguais("cd", comando)){
	    	memset(nomePastaNavegacao,'\0', 16);
	        for(i = 3; comando[i] != 0; i++){
	            nomePastaNavegacao[k] = comando[i];
	            k++;
	        }
	        *cd=true;
        	listaPastasArquivos();
		}
		else if(iguais("mkdir", comando)){
			for(i = 6; comando[i] != 0; i++){
	            nomePasta[k] = comando[i];
	            k++;
       		 }
       		 *cd = false;
			 confirmaDisponibilidadeP();
		}
		else if(iguais("type", comando)){
			memset(nomeFile,'\0', 16);
			for(i = 5; comando[i] != 0; i++){
	            nomeFile[k] = comando[i];
	            k++;
       		 }
       		 posicaoConteudo = verificaArquivo(nomeFile);
       		 exibeType();


		}else if(iguais("copy", comando)){
			int i=5;
			int j=0;
			int barra =0;
			string novoNome;
			string novoNome2;
			novoNome.clear();
			conteudoLinha.clear();
			novoNome2.clear();
			memset(nomeFile,'\0', 30);
			memset(nomeFile2,'\0', 30);
			for(i = 5; comando[i] != 0 && comando[i] != 32; i++){
				if(comando[i] =='/'){
					barra++;
				}
	            nomeFile[k] = comando[i];
	            k++;
       		 }

			 int x=0;
			 int barra2 =0;
       		 for(int j=i+1;comando[j] != 0 && comando[j] != 32; j++){
       		 	if(comando[j] =='/'){
					barra2++;
				}
	            nomeFile2[x] = comando[j];
	            x++;
       		 }
       		 j=0;
       		 for(i=0;nomeFile[i] !=0 && nomeFile[i] != 32;i++){
       		 		if(nomeFile[i] == '/'){
       		 			barra--;
       		 			i++;
					}
       		 		if(barra ==0){
       		 			novoNome += nomeFile[i];
					}
					
			}
			
			for(i=0;nomeFile2[i] !=0 && nomeFile2[i] != 32;i++){
       		 		if(nomeFile2[i] == '/'){
       		 			barra2--;
       		 			i++;
					}
       		 		if(barra2 ==0){
       		 			novoNome2 += nomeFile2[i];
					}
					
			}
			
			
			
			
			char cstr[novoNome.size() + 1];
			strcpy(cstr, novoNome.c_str());
				
			posicaoConteudo = verificaArquivo(cstr);
			if(posicaoConteudo == -1){
				cout << "Arquivo não existe" <<endl;
			}else{
				cout<<"Recupera conteudo"<<endl;
				recuperaConteudo();
				cout<<"Arquivo existe"<<endl;
				copiaArquivo(novoNome2, conteudoLinha);
			}
			
			cout<<"Nome arquivos"<<endl;
			cout << cstr << endl;
			cout << novoNome2 << endl;
			
			cout<<"Verifica arquivo existe"<<endl;
			cout << posicaoConteudo << endl;
			
			
			
		}
	    else if(iguais("exit",comando)){
	        return 0;
	    }


	}





	system("pause");
	return 0;
}
