# Fishing-Exceptions


Реализуйте простую игру-симуляцию ловли рыбы. Игровое поле представляет собой девять секторов условного пруда. В начале игры в одном из этих секторов с помощью генератора случайных чисел оказывается рыба. Точно так же, случайным образом, по секторам пруда распределяются и три сапога. Сапог и рыба при этом не могут находиться в одном и том же секторе одновременно, как и несколько сапог сразу в одном из секторов.

Игрок закидывает удочку с приманкой в один из секторов, номер которого вводится стандартным способом через консоль. Задача игрока — угадать сектор, в котором находится рыба и, таким образом, поймать её. Если игрок попал на пустой сектор, то удочку надо забросить повторно. Если игрок поймал сапог, то игра завершается с отрицательным результатом.

Реализовать задачу нужно с помощью исключений: когда успешный заброс удочки генерирует специальное пользовательское исключение, после чего программа должна завершиться и оповестить пользователя об успешной рыбалке и количестве попыток, которое ему для этого потребовалось. Если же был пойман сапог, то должно выводиться сообщение о неудачной ловле.
