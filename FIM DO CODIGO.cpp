#include <stdio.h> //biblioteca de comunicação com o usuario 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocaçãoes de texto por região 
#include <string.h> // responsavel por cuidar das string´s 

int registro() //FUNÇAO RESPONSAVEL POR CADASTRAS OS USUSARIOS NO SISTEMA 
{
	//INICIO DA CRIAÇAO DAS VARIAVES/ STRING´S 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final DA CRIAÇAO DAS VARIAVES/ STRING´S
	
	
	printf("digite o CPF a ser cadastrado: "); // coletando informações dos usuarios 
	scanf("%s" , cpf); // %s referi-se as string´s
	
	strcpy(arquivo , cpf); // responsavel por copia os valores das string´s
	
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
    printf("Não foi posivel abrir o arquivo, não localizado!\n\n ");
    }
    
    while(fgets(conteudo, 200,file) != NULL)
    {
	
    printf("\nessa são as infomações do usuário: ");
    printf("%s", conteudo);
    printf("\n\n");
    
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado!\n ");
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
    	
    	printf("### cartório da EBAC ###\n\n");
    	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - registrar nomes\n");
    	printf("\t2 - consultar  nomes\n");
	    printf("\t3 - deletar nomes\n\n");
    	printf("opção: "); //fim do menu
	
	    scanf("%d", &opcao); //Armazenamento a escolha do usuario
 
        system("cls");
        
        switch(opcao)  // inico da seleção do menu
        {
            case 1:
            registro(); //chamada de funções 
			break;	
            	
            case 2:
            consulta();
            break;
        
		    case 3:
	        deletar();
			break;
			
	        
			default:
			printf("opção indisponivel no momento!\n\n");
			system("pause");
			break;	
		}
                     
	   
	}
	   
}     
        





















 

