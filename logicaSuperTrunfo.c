#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    //variaveis para preenchimentos das cartas, com vetor para que possem ser armazenados 2 valores diferentes usando a mesma variavel
    char pais[2][50];
    char estado[2][50];
    char cod_cidade[2][5];
    char nome[2][50];
    unsigned int pop[2]; //população
    float area[2];
    float pib[2];
    unsigned int p_tur[2]; // ponto turistico

    //Variaveis que farão calculos com base nos dados inseridos
    float dens_pop[2]; //Desidade populacional
    float per_cap[2]; //PIB per capita
    float poder[2]; //super poder das cartas

    int escolha; //Escolha do menu interativo
    int vencedor[2] = {0, 0};

    //Menu interativo para o usuário decidir o que quer fazer.
    printf("--------------- MENU INTERATIVO --------------- \n \n");
    printf("O que gostaria de fazer? \n");
    printf("1 - Iniciar o jogo \n");
    printf("2 - Regras \n");
    printf("3 - Sair \n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: //Iniciando o jogo 
            // Cadastro das Cartas:
            printf("\n\n\n############################### VAMOS JOGAR?? ############################### \n\n");

            printf("\n \n --------------- REGISTRO DAS CARTAS ---------------");

            //a estrutura de repetição for vai rodar 2 vezes e armazenar o dados inseridos nos vetores.
            for (int i = 0; i < 2; i++) {
                printf("\n\n --------------- Insira os dados da %dº carta --------------- \n \n", i + 1);
                printf("Qual o país da %dº carta?\n", i + 1);
                scanf("%s", &pais[i]);

                printf("\nQual estado deste pais e referente a %dº carta?\n", i + 1);
                scanf("%s", &estado[i], "\n \n");

                printf("\nInsira o código da cidade da %dº carta?\n", i + 1);
                printf("Obs: Lembrando que o código em questão, deve conter:\n");
                printf("- a letra referente ao estado, sendo elas de A-H \n");
                printf("- e o número referente a cidade, sendo eles de 001-004 \n");
                printf("EX: A001, B002, C003 \n");
                scanf("%s", &cod_cidade[i]);

                printf("\nQual a cidade da %dº carta?\n", i + 1);
                scanf("%s", &nome[i]);

                printf("\nQual o numero de habitantes da cidade em questão?\n");
                scanf("%u", &pop[i]);

                printf("\nQual a área da cidade?\n");
                scanf("%f", &area[i]);

                printf("\nQual o valor do PIB desta cidade?\n");
                scanf("%f", &pib[i]);

                printf("\nA cidade em questão tem quantos pontos turisticos?\n");
                scanf("%u", &p_tur[i]);

                //calcula a densidade populacional, PIB per capita e super poder
                dens_pop[i] = pop[i] / area[i];
                per_cap[i] = pib[i] / pop[i];
                poder[i] = pop[i] + area[i] + pib[i] + p_tur[i] + dens_pop[i] + per_cap[i];
            }

            //comparação das cartas
            printf("--------------- COMPARAÇÃO DAS PROPRIEDADES --------------- \n \n");

            //escolha aleatoria da propriedade a ser comparada
            
            srand(time(0)); //gerador de numeros aleatorios
            int pc[2];
            pc[0]= rand() % 7 + 1; //Aqui ficara armazenada a escolha do computador em relação as propriedades

            //criação da segunda propriedade aleatoria, usando o do-while para ganrantir que seja diferente do pc[0]
            do {
                pc[1] = rand() % 7 + 1;
            } while (pc[1] == pc[0]);

            //a estrutura de repetição for vai rodar 2 vezes para apresentar no terminal o resultado das comparações das propriedades.
            for (int i = 0; i < 2; i++){
                printf("--------------- %dº PROPRIEDADE --------------- \n\n", i + 1);

                //Switch para receber o valor aleatorio escolhido pelo pc e comparar a propriedade certa
                switch (pc[i]){
                    case 1: //Compara população

                        printf("*** COMPARANDO POPULAÇÃO *** \n\n");

                        if (pop[0] == pop[1]) //Compara se os valores inserido nas variaveis sao iguais resultando em empate das cartas
                            printf("As cartas empataram!! \n\n");
                        else{
                            int maior = (pop[0] > pop[1]) ? pop[0] : pop[1]; //Uso de função ternária para definir qual das duas cartas e a vencedora
                            printf("A maior população é: %d !\n\n", maior);//Printf da carta vencedora

                            //Armazena em uma variavel qual a carta vencedora com base em pontos.
                            if(maior == pop[0]) //Aqui é conferido se a variavel armazenada pela função ternaria e primeira carta.
                                vencedor[0]++;
                            else //Se não for, entao o ponto é inserido para a segunda carta
                                vencedor[1]++;
                        }
                        break;
                    
                    case 2: //Compara área

                        printf("*** COMPARANDO ÁREA *** \n\n");

                        if (area[0] == area[1])
                            printf("As cartas empataram!! \n\n");
                        else{
                            float maior = (area[0] > area[1]) ? area[0] : area[1];
                            printf("A maior area é: %.2f !\n\n", maior);
                            if(maior == area[0])
                                vencedor[0]++;
                            else
                                vencedor[1]++;
                        }
                        break;

                    case 3: //Compara PIB

                        printf("*** COMPARANDO PIB *** \n\n");

                        if (pib[0] == pib[1])
                            printf("As cartas empataram!! \n\n");
                        else{
                            float maior = (pib[0] > pib[1]) ? pib[0] : pib[1];
                            printf("O maior PIB é: %.2f !\n\n", maior);
                            if(maior == pib[0])
                                vencedor[0]++;
                            else
                                vencedor[1]++;
                        }
                        break;
                    
                    case 4: //Compara ponto turistico

                        printf("*** COMPARANDO PONTO TURISTICO *** \n\n");

                        if (p_tur[0] == p_tur[1])
                            printf("As cartas empataram!! \n\n");
                        else{
                            int maior = (p_tur[0] > p_tur[1]) ? p_tur[0] : p_tur[1];
                            printf("A maior quantidade de pontos turisticos é: %d !\n\n", maior);
                            if(maior == p_tur[0])
                                vencedor[0]++;
                            else
                                vencedor[1]++;
                        }
                        break;

                    case 5: //Compara densidade populacional

                        printf("*** COMPARANDO DENSIDADE POPULACIONAL *** \n\n");

                        if (dens_pop[0] == dens_pop[1])
                            printf("As cartas empataram!! \n\n");
                        else{
                            float menor = (dens_pop[0] < dens_pop[1]) ? dens_pop[0] : dens_pop[1];
                            printf("A menor Desnidade Populacional é: %.2f !\n\n", menor);
                            if(menor == dens_pop[0])
                                vencedor[0]++;
                            else
                                vencedor[1]++;
                        }
                        break;

                    case 6: //Compara PIB per capita

                        printf("*** COMPARANDO PIB PER CAPITA *** \n\n");

                        if (per_cap[0] == per_cap[1])
                            printf("As cartas empataram!! \n\n");
                        else{
                            float maior = (per_cap[0] > per_cap[1]) ? per_cap[0] : per_cap[1];
                            printf("O maior PIB Per Capita é: %.2f !\n\n", maior);
                            if(maior == per_cap[0])
                                vencedor[0]++;
                            else
                                vencedor[1]++;
                        }
                        break;

                    case 7: //Compara super poder

                        printf("*** COMPARANDO SUPER PODER *** \n\n");

                        if (poder[0] == poder[1])
                            printf("As cartas empataram!! \n\n");
                        else{
                            float maior = (poder[0] > poder[1]) ? poder[0] : poder[1];
                            printf("O maior super poder é: %.2f !\n\n", maior);
                            if(maior == poder[0])
                                vencedor[0]++;
                            else
                                vencedor[1]++;
                        }
                        break;

                    default:
                        break;
                }
            }

            //Comparando os pontos para definir a carta vencedora
            if (vencedor[0] > vencedor[1]) { //Se a primeira carta é a vencedora
                printf("A carta vencedora é: %s !!\n", cod_cidade[0]);
                printf("Primeira carta inserida\n\n");
            } else if (vencedor[1] > vencedor[0]) { //se nao-se a segunda carta for vencedora
                printf("A carta vencedora é: %s !! \n", cod_cidade[1]);
                printf("Segunda carta inserida \n\n");
            } else{ //Se nao há vencedor as cartas empataram.
                printf("Não houve vencedor!\n");
                printf("As cartas empataram\n\n");
            }
            break;
        
        case 2: //Informa as regras do jogo
            printf("--------------- REGRAS: --------------- \n\n");
            printf("1- Cadastre a carta com base nas propriedades pedidas; \n");
            printf("2- Após o cadastro, será escolhida de forma aleatoria quais propriedades serão comparadas; \n");
            printf("3- A carta que tiver ganhado mais vezes nas comparações da propriedade é a vencedora.\n \n");
            break;
        
        case 3: // Saindo do programa
            printf("--------------- SAINDO... --------------- \n \n");
            break;
        
        default: //Caso seja inserido um valor diferente de 1 a 3, resultando em erro
            printf("--------------- ESCOLHA INVÁLIDA --------------- \n\n");
            break;
    }
    return 0;
}