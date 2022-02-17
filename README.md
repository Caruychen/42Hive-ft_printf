# 42Hive-ft_printf

## Disclaimer
At Hive Helsinki, a 42 Network school, students must write projects according to the "norme". Many formats are restricted, so the code may look surprising in some places.

## About
The built-in C Library functions we are allowed to use for almost all of our projects are highly limited. Generally, we can only use the following:
* write
* malloc
* free
* exit

With such limited resources available, we must recode much of our own libraries. In particular, it's time we made our printf, which has an undeniable utility to a coder. 
> The versatility of the printf function in C represents a great exercise in programming for us. This project is of moderate difficulty. It will enable you to discover variadic functions in C in a particularly relevant context as well as learn about a great example of a basic “dispatcher” in C via the use of an array of function’s pointers.

## Description
printf is prototyped as:
```
int printf(const char *format, ...);
```
where `format` is a character string, and is composed of zero or more directives. The directives specify how subsequent optional arguments are converted for output.

The directives are: ordinary characters (not %), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

The conversion specification is introduced with the character %, and ends with a *conversion specifier*. In between, there may be (in this order) zero or more *flags*, an optional minimum *field width*, an optional *precision* and an optional *length* modifier. The overall syntax is:
```
%[$][flags][width][.precision][length modifier]conversion
```

