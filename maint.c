#include "mapa.c"
#include<windows.h>

void menuzitinho()
{

    //vari�veis
    char nome[31],a;
    int tamanhoCodinome, aux,escMenu, mapinha, menu, escMenuzinho, escNM,c,sair;
    int score = 0;
    int mapa[10][10];
    int i, j;
    int o,p;
    int *m=&o, *n=&p;
    int ar, as;
    int br, bs;
    int cr, cs;
    int dr, ds;
    int er, es;

    int key_up = 72;
    int key_down = 80;
    int key_left = 75;
    int key_right = 77;
    system("cls");
    system("COLOR F0");
    geraMapa(mapa);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            switch(mapa[i][j])
            {
            case 0:
                printf(" %c ", 166);
                break;
            case 1:
                printf(" %c ", 30);
                break;
            case 2:
                printf(" %c ", 127);
                break;
            case 3:
                printf(" %c ", 4);
                break;
            case 4:
                printf(" %c ", 164);
                break;
                printf(" %d ", mapa[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n(1) Movimentar NuclearBot \n(2) Iniciar uma nova miss�o; \n(3) Sair do NBSys.\n ");
    scanf("%i",&escMenuzinho);
    switch(escMenuzinho)
    {
    case 1:

        system("cls");
        printf("****JOGO****");
        printf("\n Nesta tela voc� inicia uma nova miss�o \n");
        geraMapa(mapa);
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {

                switch(mapa[i][j])
                {
                case 0:
                    printf(" %c ", 166);
                    break;
                case 1:
                    printf(" %c ", 30);
                    break;
                case 2:
                    printf(" %c ", 127);
                    break;
                case 3:
                    printf(" %c ", 4);
                    break;
                case 4:
                    printf(" %c ", 164);
                    break;

                    printf(" %d ", mapa[i][j]);
                }

            }
            printf("\n");
        }
        while (1)
        {
            if ( kbhit() )
            {

                c = getch();
                if (c == key_up)
                {
                    procuraPacman(mapa,m,n);
                    ar=o, as=p;
                    br=o, bs=p;
                    cr=o, cs=p;
                    dr=o, ds=p;
                    er=o, es=p;

                    if(mapa[--ar][as]==3)
                    {
                        printf("\n Um obstaculo lhe atingiu e voce perdeu! Voc� n�o tem sorte mesmo.");
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    else if (mapa[--br][bs]>10 || mapa[--er][es]<0)
                    {

                        printf("\n Infelizmente voc� caiu do mapa :((((");
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    else if ( mapa[--cr][cs]==4)
                    {
                        score = score + 10;
                    }
                    else if ( mapa[--dr][ds]==2)
                    {
                        score = score + 50;
                        printf("\n Parab�ns Voc� conseguiu atingir um dos objetivos!!!!");
                        printf(" \n %s + %i",nome, score);
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    mapa[o][p] = 0;
                    mapa[--o][p] = 1;
                    system("cls");

                    atualizaMapa(mapa);
                    for (i=0; i<10; i++)
                    {
                        for (j=0; j<10; j++)
                        {

                            printf(" %d ", mapa[i][j]);

                        }
                        printf("\n");
                    }
                }
                else if(c == key_right)
                {

                    procuraPacman(mapa,m,n);
                    ar=o, as=p;
                    br=o, bs=p;
                    cr=o, cs=p;
                    dr=o, ds=p;
                    er=o, es=p;

                    if(mapa[ar][++as]==3)
                    {
                        printf("\n Um obstaculo lhe atingiu e voce perdeu! Voc� n�o tem sorte mesmo.");
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    else if (mapa[br][++bs]>10 || mapa[er][++es]<0)
                    {

                        printf("\n Infelizmente voc� caiu do mapa :((((");
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    else if ( mapa[cr][++cs]==4)
                    {
                        score = score + 10;
                    }
                    else if ( mapa[dr][++ds]==2)
                    {
                        score = score + 50;
                        printf("\n Parab�ns Voc� conseguiu atingir um dos objetivos!!!!");
                        printf(" \n %s + %i",nome, score);
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    mapa[o][p] = 0;
                    mapa[o][++p] = 1;
                    system("cls");
                    atualizaMapa(mapa);
                    for (i=0; i<10; i++)
                    {
                        for (j=0; j<10; j++)
                        {

                            printf(" %d ", mapa[i][j]);

                        }
                        printf("\n");
                    }
                }
                else if(c == key_down)
                {
                    procuraPacman(mapa,m,n);
                    ar=o, as=p;
                    br=o, bs=p;
                    cr=o, cs=p;
                    dr=o, ds=p;
                    er=o, es=p;
                    if(mapa[++ar][as]==3)
                    {
                        printf("\n Um obstaculo lhe atingiu e voce perdeu! Voc� n�o tem sorte mesmo.");
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    else if (mapa[++br][bs]>10 || mapa[++er][es]<0)
                    {

                        printf("\n Infelizmente voc� caiu do mapa :((((");
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    else if ( mapa[++cr][cs]==4)
                    {
                        score = score + 10;
                    }
                    else if ( mapa[++dr][ds]==2)
                    {
                        score = score + 50;
                        printf("\n Parab�ns Voc� conseguiu atingir um dos objetivos!!!!");
                        printf(" \n %s + %i",nome, score);
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    mapa[o][p] = 0;
                    mapa[++o][p] = 1;
                    system("cls");

                    atualizaMapa(mapa);
                    for (i=0; i<10; i++)
                    {
                        for (j=0; j<10; j++)
                        {

                            printf(" %d ", mapa[i][j]);

                        }
                        printf("\n");
                    }
                }
                else if(c == key_left)
                {
                    procuraPacman(mapa,m,n);
                    ar=o, as=p;
                    br=o, bs=p;
                    cr=o, cs=p;
                    dr=o, ds=p;
                    er=o, es=p;
                    if(mapa[ar][--as]==3)
                    {
                        printf("\n Um obstaculo lhe atingiu e voce perdeu! Voc� n�o tem sorte mesmo.");
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    else if (mapa[br][--bs]>10 || mapa[er][--es]<0)
                    {

                        printf("\n Infelizmente voc� caiu do mapa :((((");
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    else if ( mapa[cr][--cs]==4)
                    {
                        score = score + 10;
                    }
                    else if ( mapa[dr][--ds]==2)
                    {
                        score = score + 50;
                        printf("\n Parab�ns Voc� conseguiu atingir um dos objetivos!!!!");
                        printf(" \n %s + %i",nome, score);
                        sleep(5);
                        system("cls");
                        menuzitinho();
                    }
                    mapa[o][p] = 0;
                    mapa[o][--p] = 1;
                    system("cls");

                    atualizaMapa(mapa);
                    for (i=0; i<10; i++)
                    {
                        for (j=0; j<10; j++)
                        {

                            printf(" %d ", mapa[i][j]);

                        }
                        printf("\n");
                    }
                }
            }



        }
        break;

    case 2:
        fflush(stdin);

        while (escMenuzinho == 2)
        {
            printf("\n Nesta tela voc� inicia uma nova miss�o \n");
            printf("\n Deseja cancelar a miss�o atual e gerar uma nova? (1- sim ou 2- n�o)");
            scanf("%i", &escNM);
            if(escNM == 1)
            {
                menuzitinho();

                while (1)
                {
                    if ( kbhit() )
                    {

                        c = getch();
                        if (c == key_up)
                        {
                            procuraPacman(mapa,m,n);
                            ar=o, as=p;
                            br=o, bs=p;
                            cr=o, cs=p;
                            dr=o, ds=p;
                            er=o, es=p;

                            if(mapa[--ar][as]==3)
                            {
                                printf("\n Um obstaculo lhe atingiu e voce perdeu! Voc� n�o tem sorte mesmo.");
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            else if (mapa[--br][bs]>10 || mapa[--er][es]<0)
                            {

                                printf("\n Infelizmente voc� caiu do mapa :((((");
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            else if ( mapa[--cr][cs]==4)
                            {
                                score = score + 10;
                            }
                            else if ( mapa[--dr][ds]==2)
                            {
                                score = score + 50;
                                printf("\n Parab�ns Voc� conseguiu atingir um dos objetivos!!!!");
                                printf(" \n %s %i",nome, score);
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            mapa[o][p] = 0;
                            mapa[--o][p] = 1;
                            system("cls");

                            atualizaMapa(mapa);
                            for (i=0; i<10; i++)
                            {
                                for (j=0; j<10; j++)
                                {

                                    printf(" %d ", mapa[i][j]);

                                }
                                printf("\n");
                            }
                        }
                        else if(c == key_right)
                        {

                            procuraPacman(mapa,m,n);
                            ar=o, as=p;
                            br=o, bs=p;
                            cr=o, cs=p;
                            dr=o, ds=p;
                            er=o, es=p;

                            if(mapa[ar][++as]==3)
                            {
                                printf("\n Um obstaculo lhe atingiu e voce perdeu! Voc� n�o tem sorte mesmo.");
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            else if (mapa[br][++bs]>10 || mapa[er][++es]<0)
                            {

                                printf("\n Infelizmente voc� caiu do mapa :((((");
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            else if ( mapa[cr][++cs]==4)
                            {
                                score = score + 10;
                            }
                            else if ( mapa[dr][++ds]==2)
                            {
                                score = score + 50;
                                printf("\n Parab�ns Voc� conseguiu atingir um dos objetivos!!!!");
                                printf(" \n %s + %i",nome, score);
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            mapa[o][p] = 0;
                            mapa[o][++p] = 1;
                            system("cls");
                            atualizaMapa(mapa);
                            for (i=0; i<10; i++)
                            {
                                for (j=0; j<10; j++)
                                {

                                    printf(" %d ", mapa[i][j]);

                                }
                                printf("\n");
                            }
                        }
                        else if(c == key_down)
                        {
                            procuraPacman(mapa,m,n);
                            ar=o, as=p;
                            br=o, bs=p;
                            cr=o, cs=p;
                            dr=o, ds=p;
                            er=o, es=p;
                            if(mapa[++ar][as]==3)
                            {
                                printf("\n Um obstaculo lhe atingiu e voce perdeu! Voc� n�o tem sorte mesmo.");
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            else if (mapa[++br][bs]>10 || mapa[++er][es]<0)
                            {

                                printf("\n Infelizmente voc� caiu do mapa :((((");
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            else if ( mapa[++cr][cs]==4)
                            {
                                score = score + 10;
                            }
                            else if ( mapa[++dr][ds]==2)
                            {
                                score = score + 50;
                                printf("\n Parab�ns Voc� conseguiu atingir um dos objetivos!!!!");
                                printf(" \n %s +  %i",nome, score);
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            mapa[o][p] = 0;
                            mapa[++o][p] = 1;
                            system("cls");

                            atualizaMapa(mapa);
                            for (i=0; i<10; i++)
                            {
                                for (j=0; j<10; j++)
                                {

                                    printf(" %d ", mapa[i][j]);

                                }
                                printf("\n");
                            }
                        }
                        else if(c == key_left)
                        {
                            procuraPacman(mapa,m,n);
                            ar=o, as=p;
                            br=o, bs=p;
                            cr=o, cs=p;
                            dr=o, ds=p;
                            er=o, es=p;
                            if(mapa[ar][--as]==3)
                            {
                                printf("\n Um obstaculo lhe atingiu e voce perdeu! Voc� n�o tem sorte mesmo.");
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            else if (mapa[br][--bs]>10 || mapa[er][--es]<0)
                            {

                                printf("\n Infelizmente voc� caiu do mapa :((((");
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            else if ( mapa[cr][--cs]==4)
                            {
                                score = score + 10;
                            }
                            else if ( mapa[dr][--ds]==2)
                            {
                                score = score + 50;
                                printf("\n Parab�ns Voc� conseguiu atingir um dos objetivos!!!!");
                                printf(" \n %s +%i",nome, score);
                                sleep(5);
                                system("cls");
                                menuzitinho();
                            }
                            mapa[o][p] = 0;
                            mapa[o][--p] = 1;
                            system("cls");

                            atualizaMapa(mapa);
                            for (i=0; i<10; i++)
                            {
                                for (j=0; j<10; j++)
                                {

                                    printf(" %d ", mapa[i][j]);

                                }
                                printf("\n");
                            }
                        }
                    }
                }
                procuraPacman(mapa,m,n);
            }
            else if(escNM == 2)
            {

                system("cls");
                menuzinho();
            }

        }

        break;

    case 3:
        printf("\n Deseja sair da miss�o e fechar o programa? (1- sim ou 2- n�o)");
        scanf("%i", &sair);
        if(sair==1)
        {
            system("cls");
            printf("\n **********************");
            printf("\n AT� A PROXIMA!!!!!!!!");
            exit(1);
        }
        else if(sair==2)
        {
            menuzitinho();
        }
        break;

    default:
        printf("\nComando inv�lido\n");
        menuzitinho();

        break;
    }
}

void menuzinho() // transformando o menu numa fun��o yay
{
    //vari�veis3
    int sw,sair;
    int mapa[10][10];




    printf("\n(1) Iniciar uma nova miss�o; \n(2) Sair do NBSys.\n ");
    scanf("%d", &sw); //(tudo) armazena o pre�o x unidade, logo n�o pode assumir um valor negativo(Ex: caso o cliente digite -4 unidades)
    switch(sw)
    {
    case 1:
        printf("\n Nesta tela voc� inicia uma nova miss�o \n");

        menuzitinho();

    case 2:
        printf("\n Deseja sair da miss�o e fechar o programa? (1- sim ou 2- n�o)");
        scanf("%i", &sair);
        if(sair==1)
        {
            system("cls");
            printf("\n **********************");
            printf("\n AT� A PROXIMA!!!!!!!!");
            exit(1);
        }
        else if(sair==2)
        {
            menuzinho();
        }
        break;
    default:
        printf("\nComando inv�lido\n");
        menuzinho();
    }
    printf("\n====================================================\n");




}
void procuraPacman(int mapa[10][10], int* m, int* n)
{
    int i, j;
    for (i=0; i<10; i++)
    {
        for (j=0; j<10; j++)
        {
            if (mapa[i][j] == 1)
            {
                *m = i;
                *n = j;
            }
        }
    }
}
int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    //vari�veis 2
    char nome[31];
    int tamanhoCodinome, aux;

    //TI
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;


   GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

                                                  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                                                printf("\n *-----------------------------* \n"
                                                       "\n|                             |  \n"
                                                       "\n|                             |  \n"
                                                       "\n|                             |  \n"
                                                       "\n|   BOAS VINDAS AO NBSYS!     |  \n"
                                                       "\n|                             |  \n"
                                                       "\n|                             |  \n"
                                                       "\n|                             |  \n"
                                                       "\n *-----------------------------* \n");

   SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("Projeto desenvolvido por: Giulia, Guilherme e Jo�o");

    //cadastro do codinome
    printf("\n \rPara come�ar informe seu codinome : \n");
    scanf("%[^\n]", nome);
    tamanhoCodinome = strlen(nome);
    fflush(stdin);
    while(tamanhoCodinome<3 || tamanhoCodinome>30)
    {
        fflush(stdin);
        printf("codinome inv�lido, por favor digite um codinome v�lido no sistema!\n");
        scanf("%[^\n]", nome);
        tamanhoCodinome = strlen(nome);

    }
//looop,para verificar se o usuario quer trocar seus dados!
    fflush(stdin);
    printf("\nSeu codinome : %s esta armazenado no sistema! Digite 0 se deseja mudar ou qualquer numero para continuar: \n", nome);
    fflush(stdin);
    scanf("%d", &aux);

    fflush(stdin);
    while(!aux)
    {
        fflush(stdin);
        printf("Digite seu codinome\n");
        scanf("%[^\n]",nome);
        tamanhoCodinome = strlen(nome);
        while(tamanhoCodinome<3 || tamanhoCodinome>30)
        {
            fflush(stdin);
            printf("codinome inv�lido, por favor digite um codinome v�lido no sistema!\n");
            scanf("%[^\n]", nome);
            tamanhoCodinome = strlen(nome);

        }
        printf("\nSeu codinome : %s esta armazenado no sistema! Digite 0 se deseja mudar ou qualquer numero para continuar: \n", nome);
        scanf("%d", &aux);


    }
    system("cls");
    sleep(3);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    printf( "\n Seja bem-vindo, %s.", nome);
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf( "\n A usina nuclear de Curitiba se encontra com problemas, houve um mau funcionamento no vaso de press�o do reator e ele est� altamente inst�vel."
            "\n Sua miss�o � controlar o mais novo modelo do Nuclear Bot, o LDAA-21, e mov�-lo pela usina de forma que chegue � sala de controle, e\n desative o reator no painel de controle.\n"
            "\n O novo sistema lhe permite visualizar uma transmiss�o via sat�lite o interior da usina, para maior precis�o enquanto controla o rob�"
            "\n Seu objetivo � chegar ao painel de controle e desativar o reator para evitar maiores cat�strofes, e ao longo do caminho fechar v�lvulas com vazamento de g�s"
            "\n Ao desativar o painel, o sistema lhe atribur� 50 pontos, e para cada v�lvula, 10. Assim que o painel ser desativado, a miss�o ser� encerrada e ser� um sucesso."
            "\n Aten��o! No seu caminho v�o ter m�ltiplos obst�culos que ser�o atualizados conforme o rob� move. Se atingir um desses obst�culos,\n a miss�o ser� encerrada e ser� um fracasso.\n"
            "\n Para movimentar o rob� utilize as setas direcionais do seu teclado. Para cada quadro andado no mapa, o rob� se locomover� 5 metros."
            "\n Boa sorte, contamos com voc� para evitar esta cat�strofe.");
    printf("\n\n\n Voc� gostaria de:");
       menuzinho();


}
