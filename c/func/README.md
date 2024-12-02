## Function

### Undefined or Unspecific

**You must not evaluate value at once in one line**
Let `int a=3;`.

```c
(a++) - (++a);
```

This code can make `undefined` or `unspecific` behaviors.
Many operators including `+`, `++` don't guarantee the order of evaluation.
Explicit evaluation would be `;`.

## Declaration of Variable

This below code could make `compile error`.

```c
int a = 3;
printf("%d\n", a);

int b = 5;
int result = a+b;
```

## Block

This below code can work. But not recommended

```c
int a = 3;
print("%d\n", a);
{
    int b = 5;
}
```

Variable that declares at global are at Data section of RAM.