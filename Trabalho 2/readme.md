Lucas Lopes Silva - Turma M2

Trabalho prático 2

O sistema de arquivos Leetcode mantém um registro cada vez que algum usuário executa uma
operação de mudança de pasta.
As operações são descritas abaixo:
"../" : Move para a pasta pai da pasta atual. (Se você já estiver na pasta principal, permaneça na
mesma pasta).
"./" : Permanece na mesma pasta.
"x/" : Mover para a pasta filha chamada x (esta pasta sempre existirá).
Você recebe uma lista de strings
logs onde logs[i] é a operação executada pelo usuário na i-ésima etapa.
O sistema de arquivos é iniciado na pasta principal e, em seguida, as operações nos logs são
executadas.
Retorna o número mínimo de operações necessárias para voltar à pasta principal após as operações
de mudança de pasta.
