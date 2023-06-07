#include <stdio.h> //biblioteca de comunica��o com o usuario 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��oes de texto por regi�o 
#include <string.h> // responsavel por cuidar das string�s 

int registro() //FUN�AO RESPONSAVEL POR CADASTRAS OS USUSARIOS NO SISTEMA 
{
	//INICIO DA CRIA�AO DAS VARIAVES/ STRING�S 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final DA CRIA�AO DAS VARIAVES/ STRING�S
	
	
	printf("digite o CPF a ser cadastrado: "); // coletando informa��es dos usuarios 
	scanf("%s" , cpf); // %s referi-se as string�s
	
	strcpy(arquivo , cpf); // responsavel por copia os valores das string�s
	
	FILE *file; //cria o arquivo 
	file =fopen(arquivo, "w"); //criar o arquivo, cria o arquivo e "w" write de escrever
	fprintf(file,cpf); // salva o valor da vareavel
	fclose(file); // "close=fechar" fecha o arquivo
	 
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	file = fopen (arquivo, "a"); 
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
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
    printf("N�o foi posivel abrir o arquivo, n�o localizado!\n\n ");
    }
    
    while(fgets(conteudo, 200,file) != NULL)
    {
	
    printf("\nessa s�o as infoma��es do usu�rio: ");
    printf("%s", conteudo);
    printf("\n\n");
    
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado!\n ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file =fopen(cpf,"r");
	
	
	if(file == NULL)
	{
		
	printf("Usuario deletado com sucesso!\n ");
	system("pause");
	
	}
	
}

int main()
{
     int opcao=0; //definindo variaveint teste()   
	 int laco=1;
    
    for(laco=1; laco=1;)
    {
    	
    	system("cls"); //responsavel por limpa a terla
    	
    	setlocale(LC_ALL, "portuguese"); //Definindo a Linguagem
    	
    	printf("### cart�rio da EBAC ###\n\n");
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - registrar nomes\n");
    	printf("\t2 - consultar  nomes\n");
	    printf("\t3 - deletar nomes\n\n");
    	printf("op��o: "); //fim do menu
	
	    scanf("%d", &opcao); //Armazenamento a escolha do usuario
 
        system("cls");
        
        switch(opcao)  // inico da sele��o do menu
        {
            case 1:
            registro(); //chamada de fun��es 
			break;	
            	
            case 2:
            consulta();
            break;
        
		    case 3:
	        deletar();
			break;
			
	        
			default:
			printf("op��o indisponivel no momento!\n\n");
			system("pause");
			break;	
		}
                     
	   
	}
	   
}     
        





















 

