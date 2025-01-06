#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//Final da cria��o de vari�veis/string

	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
    printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
 }   
int consultar()
 {
   	setlocale(LC_ALL, "portuguese"); //Definindo linguagem
   	
	char cpf[40];
   	char conteudo[200];
   	
   	printf("Digite o CPF a ser consultado: ");
   	scanf("%s",cpf);
   	
   	FILE *file;
   	file = fopen(cpf,"r");
   	
   	if(file == NULL)
   	{	
   	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	}
	
while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}
int deletar()   
{
    char cpf[50];
   
    printf("Digite o CPF do usu�rio ser deletado: "); // solicita o CPF a ser deletado
    scanf("%s",cpf);
   
    remove(cpf);
   
    FILE *file;
    file = fopen(cpf,"r");
   
    if(file == NULL)
    {
   	printf("\nO usu�rio n�o se encontra no sistema!. \n"); // informa que o CPF n�o foi encontrado
   	system("pause");
    }
   
   }

   
int main()
{
int opcao=0; //Definindo vari�veis
int x=1;
	
for(x=1;x=1;)
    {
	system("cls"); //Responsavel por limpar a tela
			
    setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
    printf("\t### Cart�rio da EBAC ###\n\n"); // Inicio do menu
   	printf("Escolha a op��o desejada do menu:\n\n");
   	printf("\t1 - Registrar nomes\n");
   	printf("\t2 - Consultar nomes\n");
   	printf("\t3 - Deletar nomes\n\n");
    printf("op��o: "); //Fim do menu
	
   	scanf("%d", &opcao); //Armazenando a escolha de usu�rio
	
   	system("cls"); //Responsavel por limpar a tela
    	
    switch (opcao) //Inicio da sele��o do menu
   	{
    case 1:
    registro(); // chamada de fun��es
    break;
   	    

   	case 2:
    consultar();
   	break;
   		
   	case 3:
    deletar();
   	break;
   	
   	default:
  	printf("Essa op��o n�o est� disponivel!\n");
	system("pause");
	break;
	//Fim da sele��o
	}
    }

}
