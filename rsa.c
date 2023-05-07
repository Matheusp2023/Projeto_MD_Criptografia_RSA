#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Alunos:

// Matheus Pedro da Silva
// Leonardo Lucca Holanda de Paula
// João Victor Cavalcante da Silva Correia
// Sandro Gomes Paulino
// Robson de Paula Correia dos Santos

int opcao1();
int opcao2();
int opcao3();
int opcao4();

// verificação de sistema operacional para realizar função limparTela
#ifdef _WIN32
#define limparTela() system("cls")
#else
#define limparTela() system("clear")
#endif

void gerarChavesPublicas()
{
    limparTela();
    opcao1();
}

void criptografarMensagem()
{
    limparTela();
    opcao2();
}

void descriptografarMensagem()
{
    limparTela();
    opcao3();
}

void abrirArquivoDescriptografado()
{
    limparTela();
    printf("Abrindo arquivo aguarde...\n");
    sleep(1);
    limparTela();
    opcao4();
}

void finalizarPrograma()
{
    limparTela();
    printf("Encerrando programa aguarde...\n");
    sleep(1);
}

void opcaoInvalida()
{
    limparTela();
    printf("Opção inválida. Digite outra opção.\n");
}

int main()
{
    int opcao;

    do
    {
        limparTela();
        printf("          Criptografia RSA\n\n");
        printf("-------------- Menu --------------\n\n");
        printf("(1) Gerar chaves públicas\n\n");
        printf("(2) Criptografar mensagem\n\n");
        printf("(3) Descriptografar mensagem\n\n");
        printf("(4) Ver mensagem descriptografada\n\n");
        printf("(5) Sair\n\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            gerarChavesPublicas();
            break;
        case 2:
            criptografarMensagem();
            break;
        case 3:
            descriptografarMensagem();
            break;
        case 4:
            abrirArquivoDescriptografado();
            break;
        case 5:
            finalizarPrograma();
            return 0;
        default:
            opcaoInvalida();
            break;
        }

        printf("\nPressione Enter para retornar ao menu...");
        getchar();
        getchar();
    }

    while (opcao != 5);

    return 0;
}

// Inicio do codigo para a opcao1
// Verifica se o numero é primo
int ehPrimo(long long int num)
{
    if (num < 2)
        return 0;

    for (long long int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Verifica se o numero "e" dado pelo usuario e o produto (p-1)*(q-1) são
// relativamente primos
long long int mdc(long long int a, long long int b)
{
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}

// Verifica se é primo e recebe o primeiro numero primo
long long int obterNumeroPrimo1()
{
    long long int num;
    do
    {
        printf("Digite o 1º numero primo (p): ");
        scanf("%lld", &num);

        if (ehPrimo(num))
            return num;
        else
            printf("%lld não é um número primo, digite outro numero\n", num);

    }

    while (1);
}

// Verifica se é primo e recebe o segundo numero primo
long long int obterNumeroPrimo2()
{
    long long int num;
    do
    {
        printf("Digite o 2º numero primo (q): ");
        scanf("%lld", &num);

        if (ehPrimo(num))
            return num;
        else
            printf("%lld não é um número primo, digite outro numero\n", num);

    }

    while (1);
}

// Recebe o "e" e verifica se é relativamente primo ao produto (p-1)*(q-1), para
// ser relativamente primo o mdc entre eles precisa ser 1
long long int obterRelativamentePrimo(long long int produto)
{
    long long int num;
    do
    {
        printf("Agora digite um expoente \"e\" que seja relativamente primo a "
               "\"%lld\" que é o produto (p-1)*(q-1): ",
               produto);
        scanf("%lld", &num);

        if (mdc(num, produto) == 1)
            return num;
        else
            printf("%lld nao eh relativamente primo a %lld.\n", num, produto);

    }

    while (1);
}
// Função principal da opcao1
int opcao1()
{
    long long int p, q, e, n, produto;

    p = obterNumeroPrimo1();
    q = obterNumeroPrimo2();

    n = p * q;
    produto = (p - 1) * (q - 1);

    e = obterRelativamentePrimo(produto);

    // "FILE" é uma estrutura de dados da biblioteca stdio.h, que cria a variável
    // "arquivo" onde vai armazenar as chaves públicas em um arquivo de texto
    FILE *arquivo;

    // Criação do arquivo de texto, caso um arquivo já exita com o mesmo nome ele
    // será recriado e as informações anteriores serão perdidas
    arquivo = fopen("chavesPublicas.txt", "w");

    // escrevendo as informções nesse arquivo de texto
    fprintf(arquivo, "Suas chaves públicas:\n");
    fprintf(arquivo, "e: %lld\nn: %lld\n\n", e, n);

    // Fechamento do arquivo, para garantir que os dados escritos no arquivo sejam
    // salvos corretamente
    fclose(arquivo);

    limparTela();

    // Informação de que as chaves foram geradas com sucesso e nome do arquivo em
    // que elas foram salvas
    printf("Chaves publicas geradas e salva no arquivo chavesPublicas.txt\n");

    return 0;
}

// Inicio do codigo para a opcao2

// realiza a operação numero da letra^e mod (n)
unsigned long long int potencia(unsigned long long int numeroDaLetra, unsigned long long int e, unsigned long long int n)
{
    unsigned long long int resultado = 1;

    for (int i = 0; i < e; i++)
    {
        resultado = (resultado * numeroDaLetra) % n;
    }

    return resultado;
}

// Função principal da opcao2
int opcao2()
{

    // Valores de "e" e "n" obtidos pela chave pública
    unsigned long long int e, n;

    // Declarando o vetor da mensagem encriptada
    unsigned long long int msg_encriptada[1000];
    char mensagem[1001];

    // Lista de caracteres ligando o valor deles às suas posições
    char caracteres[29] = {'0', '1', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                           'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

    // Atribui a mensagem ao vetor "mensagem" como uma string só
    printf("Digite sua mensagem de texto (até 1000 caracteres):\n");
    scanf("\n%1000[^\n]", mensagem);

    printf("Digite sua chave pública \"e\": ");
    scanf("%lld", &e);

    printf("Digite sua chave pública \"n\": ");
    scanf("%lld", &n);

    // Troca todas os caracteres para maiúsculas
    char msg_up[1001];
    for (int i = 0; i < 1000; i++)
    {
        msg_up[i] = toupper(mensagem[i]);
    }

    FILE *arquivo;
    arquivo = fopen("mensagemEncriptada.txt", "w");

    // Descobrimos quantos caracteres temos na mensagem e depois guarda a mensagem
    // encriptada no array "msg_encriptada"
    int range = strlen(msg_up);
    for (int i = 0; i < range; i++)
    {
        char aux = msg_up[i];
        for (int j = 0; j <= 29; j++)
        {
            if (aux == caracteres[j])
            {
                unsigned long long int resultado = potencia(j, e, n);
                msg_encriptada[i] = resultado;

                // Escrevendo as informções nesse arquivo de texto
                fprintf(arquivo, "%lld ", msg_encriptada[i]);
            }
        }
    }

    // Fechamento do arquivo, para garantir que os dados escritos no arquivo sejam
    // salvos corretamente
    fclose(arquivo);

    limparTela();

    printf("Mensagem encriptada e salva no arquivo mensagemEncriptada.txt\n");

    return 0;
}

// inicio do codigo para a opcao3
// Função para ler o arquivo para saber quantos caracteres ele tem
int lerArquivo(unsigned long long int num[])
{
    FILE *arquivo = fopen("mensagemEncriptada.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    int num_elementos = 0;
    while (fscanf(arquivo, "%llu", &num[num_elementos]) == 1)
    {
        num_elementos++;
    }
    return num_elementos;
}

// Colocar os numeros criptografados do arquivo no array num
void leituraNum(int range, unsigned long long int num[], FILE *arquivo)
{
    for (int i = 0; i < range; i++)
    {
        fscanf(arquivo, "%llu ", &num[i]);
    }

    return;
}

// Função para calcular o inverso de a mod b
unsigned long long int gerarS(unsigned long long int a, unsigned long long int b,
                              long long int *s, long long int *t)
{
    if (a == 0)
    {
        *s = 0;
        *t = 1;
        return b;
    }
    long long int s1, t1;
    long long int mdc = gerarS(b % a, a, &s1, &t1);
    *s = t1 - (b / a) * s1;
    *t = s1;
    return mdc;
}

// Verificação para deixar o s positivo
unsigned long long int verificarS(long long int s, unsigned long long int b)
{
    if (s >= 0)
    {
        return s;
    }
    else
    {
        s += b;
        return verificarS(s, b);
    }
}

// Exponenciação modular
unsigned long long int exponenciacaoModular(unsigned long long int denominador,
                                            unsigned long long int potencia,
                                            unsigned long long int mod,
                                            unsigned long long int simplificar)
{
    unsigned long long int n = denominador, k = potencia, d = mod;
    unsigned long long int resultado, pot;

    if (d > 4000)
        d = mod / simplificar;

    pot = n % d;
    resultado = 1;

    for (; k > 0; k /= 2)
    {
        if (k % 2 == 1)
        {
            resultado = (resultado * pot) % d;
        }

        pot = (pot * pot) % d;
    }

    return resultado;
}

// Funcao para calcular o modulo dos elementos de num elevado a d
void descriptografar(int ranger, unsigned long long int d,
                     unsigned long long int n, unsigned long long int p,
                     unsigned long long int num[],
                     unsigned long long int num_descriptografado[])
{
    for (int i = 0; i < ranger; i++)
    {
        num_descriptografado[i] = exponenciacaoModular(num[i], d, n, p);
    }

    return;
}

// Mensagem descriptografada
void mensagemDescriptografada(int ranger,
                              unsigned long long int num_descriptografado[],
                              char caracteres[], char mensagem[])
{
    for (int i = 0; i < ranger; i++)
    {
        mensagem[i] = caracteres[num_descriptografado[i]];
    }

    return;
}

// Gera o arquivo com mensagem descriptografada
void gerarArquivo(int ranger, char a[])
{

    FILE *arquivo;
    arquivo = fopen("mensagemDescriptografada.txt", "w");

    fprintf(arquivo, "Mensagem descriptografada:\n");

    for (int i = 0; i < ranger; i++)
    {
        fprintf(arquivo, "%c", a[i]);
    }

    fclose(arquivo);

    limparTela();

    printf("Mensagem descriptografada e salva no arquivo mensagemDescriptografada.txt\n");
}

// Função para descriptografia da opcao 3
void descriptografia(int range)
{
    unsigned long long int p, q, e, d;
    long long int s, t;
    unsigned long long int num_descriptografado[range], num[range];
    char mensagem[range];
    char caracteres[29] = {'0', '1', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                           'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                           'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

    printf("Digite sua chave privada \"p\": ");
    scanf("%llu", &p);

    printf("Digite sua chave privada \"q\": ");
    scanf("%llu", &q);

    printf("Digite sua chave pública \"e\": ");
    scanf("%llu", &e);

    unsigned long long n = p * q;

    FILE *arquivo = fopen("mensagemEncriptada.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    leituraNum(range, num, arquivo);

    fclose(arquivo);

    gerarS(e, (p - 1) * (q - 1), &s, &t);

    d = verificarS(s, (p - 1) * (q - 1));

    descriptografar(range, d, n, p, num, num_descriptografado);

    mensagemDescriptografada(range, num_descriptografado, caracteres, mensagem);

    gerarArquivo(range, mensagem);

    return;
}

// Funcao principal opcao 3
int opcao3()
{
    unsigned long long int numeros[1001];
    int range = lerArquivo(numeros);

    descriptografia(range);

    return 0;
}

int opcao4()
{

    char linha[3];
    FILE *arquivo;
    arquivo = fopen("mensagemDescriptografada.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fgets(linha, 3, arquivo))
    {
        printf("%s", linha);
    }

    fclose(arquivo);

    printf("\n");

    return 0;
}
