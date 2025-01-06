#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio criação de variáveis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//Final da criação de variáveis/string

	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores da string
	
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
   	printf("Não foi possivel abrir o arquivo, não localizado!.\n");	
	}
	
while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}
int deletar()   
{
    char cpf[50];
   
    printf("Digite o CPF do usuário ser deletado: "); // solicita o CPF a ser deletado
    scanf("%s",cpf);
   
    remove(cpf);
   
    FILE *file;
    file = fopen(cpf,"r");
   
    if(file == NULL)
    {
   	printf("\nO usuário não se encontra no sistema!. \n"); // informa que o CPF não foi encontrado
   	system("pause");
    }
   
   }

   
int main()
{
int opcao=0; //Definindo variáveis
int x=1;
	
for(x=1;x=1;)
    {
	system("cls"); //Responsavel por limpar a tela
			
    setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
    printf("\t### Cartório da EBAC ###\n\n"); // Inicio do menu
   	printf("Escolha a opção desejada do menu:\n\n");
   	printf("\t1 - Registrar nomes\n");
   	printf("\t2 - Consultar nomes\n");
   	printf("\t3 - Deletar nomes\n\n");
    printf("opção: "); //Fim do menu
	
   	scanf("%d", &opcao); //Armazenando a escolha de usuário
	
   	system("cls"); //Responsavel por limpar a tela
    	
    switch (opcao) //Inicio da seleção do menu
   	{
    case 1:
    registro(); // chamada de funções
    break;
   	    

   	case 2:
    consultar();
   	break;
   		
   	case 3:
    deletar();
   	break;
   	
   	default:
  	printf("Essa opção não está disponivel!\n");
	system("pause");
	break;
	//Fim da seleção
	}
    }

}
