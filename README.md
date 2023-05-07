# Projeto de Criptografia RSA | Matematica Discreta
Projeto da disciplina de Matemática Discreta sobre criptografia RSA. 2º semestre(2022.2) do curso de Engenharia da Computação na UFAL: Universidade Federal de Alagoas.
<p align="center">
  <img src="https://user-images.githubusercontent.com/91018438/204195385-acc6fcd4-05a7-4f25-87d1-cb7d5cc5c852.png" alt="animated" />
</p>

<center>
Integrantes:

  
    Matheus Pedro | Sandro Gomes | Leonardo Lucca | João Victor | Robson de Paula
 </center>
  
  

## O que é a criptografia RSA?
* A criptografia RSA consiste em uma forma de criptografar números com base na artimética modular.
* É bastante usada no ramo computacional na finalidade de obter serviços mais seguros.
* Possui como alicerce a aritmética modular, onde se explora a dificuldade de fatorar numeros compostos muito grandes em um produto de numeros primos, constituindo assim, um sistema de criptografia eficaz.

## Como funciona a criptografia RSA
* Inserção de dois números primos, p e q, e um número e coprimo com (p-1)(q-1), constituindo assim a chave pública.
* Para criptografar, basta encontrar o módulo do número atribuido a cada letra do alfabeto elevado ao expoente e com o produto de p e q.
* Pra descriptografar, basta encontrar o resto do número crifado elevado ao expoente d com o produto de p e q, sendo esse d o inverso modular do e módulo (p-1)*(q-1).

```c
criptografia: mensagem^e = numero mod (p*q)

descriptografia: numero^d = mensagem mod (p*q)

```		
<h2>Linguagem usada no projeto</h2>
<a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> </p>

## Instalação do programa

<p> Para poder instalar e executar o programa, você terá que ter instalado o GCC em sua máquina

> Exemplo:
>
> Clone esse projeto em seu computador com o comando:
> ```
> 	git clone https://github.com/Matheusp2023/Projeto_MD_Criptografia_RSA
> ```
> Acesse a pasta do projeto seu terminal:
> ```
> 	cd [Nome da pasta onde você salvou]
> ```
> Já pasta da aplicação em seu terminal, digite o seguinte comando:
> ```
> 	gcc RSA_encritpion_Final.c -o exe -lm
> ```
> 	Logo depois, basta executar com o seguinte comando:
> ```
>         ./exe
  </p>


## Execução do programa
<p> Ao inicializar o programa, você terá direito de escolha de 5 opções:
  
* Criar chaves públicas e armazená-las em um arquivo .txt
* Criptografar uma frase de até 100000 caracteres digitada pelo usuário e gerar um arquivo criptado em .txt
* Descriptografar o arquivo com a inserção de chaves públicas a critério do usuário
* Ver a mensagem dseciptografada, ou não, conforme o item 3
* Sair do programa
  <p align="center">
  <img src="https://github.com/Matheusp2023/Projeto_MD_Criptografia_RSA/blob/main/Imagem%20do%20Menu.jpg" alt="animated" />
</p>

### Arrays para números e letras de acordo com a numeração dada

```c
char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
int numero_no_alfabeto[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28};
```

# Obrigado pela atenção!
