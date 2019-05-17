# infix2postfix

This repository contains a simple algorithm written in C to convert an infix expression to a postfix expression.

## Infix expressions
You're already familiiar with infix expressions. Infix expressions are expressions that contain _operators_ (+-*/) between _operands_ (numeric constants).

Examples of infix expression are:

```
2 * 6 + 1 / 4

5 * (7 - 5)
```

According to Silvio do Lago Pereira, in its book titled [_"Estrutura de Dados em C"_](https://www.amazon.com.br/Estruturas-Dados-Uma-Abordagem-Did%C3%A1tica/dp/8536516291?tag=goog0ef-20&smid=A1ZZFT5FULY4LN&ascsubtag=go_729680143_34002717090_172477348789_pla-394069366980_c_), there is a big problem with infix expressions: the existence of priorities, either due the operators (`*` and `/` have higher priority) or due parenthesis.

## Postfix expressions
So, a long time ago, [Jan Lukasiewicz](https://en.wikipedia.org/wiki/Jan_%C5%81ukasiewicz) created a different way of treating expressions and called it **postfix notation** or _reverse Polish notation_.

Basically, it consists of moving the operators to **after** the operands - not between anymore.

The previous infix expressions written in postfix notation are:

```
2 6 * 1 4 / +

(7 5 -) 5 *
```

The advantage of this notation for computational programs is that they can be easily interpreted using a [Stack abstract data type](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)).
