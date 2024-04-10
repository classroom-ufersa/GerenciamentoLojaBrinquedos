# Sistema Loja de Brinquedos

<table>
<tr> 
Este repositório contém o Sistema de Gerenciamento de Loja de Brinquedos desenvolvido na Linguagem C para a disciplina de Algoritmos e Estruturas de Dados.
Aqui estao algumas funcionalidades disponíveis:  
</tr>
</table>


- **Funcionalidades presentes no programa**:
É possível realizar algumas atividades dentro do programa. Para utilizar essas funcionalidades, basta selecionar a desejada. As opções disponíveis são:

    - `Adicionar Sessão:` Adiciona uma nova sessão ao sistema de Gerenciamento;

    - `Remover Sessão:` Remove uma sessão do Sistema de Gerenciamento;

    - `Adicionar Brinquedo:` Adiciona um novo brinquedo em uma sessão;

    - `Remover brinquedo:` Remove um brinquedo do Sistema de Gerenciamento; 

    - `Aumentar/diminuir o estoque de um brinquedo:` De acordo com o brinquedo desejado, será possível realizar alterações em seu estoque conforme for necessário;

    - `Buscar brinquedo por nome:` Busca o brinquedo pelo o seu nome de cadastro;

    - `Listar Sessoes/Brinquedos disponíveis:` Lista todas as sessões e brinquedos que estão disponíveis; 

    - `Sair do programa:` Finaliza a execução do sistema; 

___

## **Organização do Repositório**
```
📁 - GerenciamentoLojaBrinquedos


|
└─── data
│
└─── include
        │
        ├──brinquedos.h
        ├──sessao.h    
│
└─── src
        │
        ├──brinquedos.c
        ├──sessao.c
        ├──main.c
│
└───test
│
└───README.md
```

### **Tecnologias utilizadas**
___

![c](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)


## **Execução do projeto**
- Certifique-se de que você possui algum compilador C em sua máquina. Recomendamos o uso do GCC para compilar o código.
```
gcc -o main.exe .\src\brinquedos.c .\src\sessao.c .\src\main.c
```
## **Participantes** 


<table align="center">
  <tr>    
    <td align="center">
      <a href="https://github.com/Difierro">
        <img src="https://github.com/classroom-ufersa/GerenciamentoLojaBrinquedos/assets/114101163/e9b27183-9c24-4a17-a2e1-5acdcc39c8d4" 
        width="120px;" alt="Foto de Gustavo Rodrigues"/><br>
        <sub>
          <b>Gustavo Rodrigues</b>
         </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://github.com/euduar-da">
        <img src="https://github.com/classroom-ufersa/GerenciamentoLojaBrinquedos/assets/114101163/8faa38fe-6027-4aa7-939b-bf10de1534cd" 
        width="120px;" alt="Foto de Eduarda Souza no GitHub"/><br>
        <sub>
          <b>Eduarda Souza</b>
         </sub>
      </a>
    </td>
  </tr>
</table>