# PHPSci CArray Extension
[![Build Status](https://travis-ci.org/phpsci/phpsci-ext.svg?branch=master)](https://travis-ci.org/phpsci/phpsci-ext)
[![Documentation Status](https://readthedocs.org/projects/phpsci-carray/badge/?version=latest)](http://php-learn.readthedocs.io/en/latest/?badge=latest)

<p align="center">
  <img src="https://i.imgur.com/QoIbhqj.png" width="70%" />
</p>

This is the extension used by [PHPSci](https://www.github.com/phpsci/phpsci). 
It offers the CArray object in place of PHP arrays to make scientific calculations faster.


Although it is not necessary, or you want to create your own library of arrays, we recommend that you use
[PHPSci](https://www.github.com/phpsci/phpsci) together with this extension.


---

## Installing

It's really easy to compile this extension using Linux environments.

#### Requirements

- php-devel (php-dev)
- PHP 7.2
- OpenBLAS

#### Ubuntu 16.04
```commandline
$ add-apt-repository -y ppa:ondrej/php
$ apt-get update
$ apt-get install libblas-dev libatlas-base-dev php7.2-dev
$ phpize
$ ./configure
$ make test
$ make install
```
#### Ubuntu 14.04
```commandline
$ add-apt-repository -y ppa:ondrej/php
$ apt-get update
$ apt-get install libopenblas-dev liblapacke-dev php7.2-dev
$ phpize
$ ./configure
$ make test
$ make install
```

> Don't forget to check if the extension is enabled in your php.ini file.

> **Apache/NGINX Users:** Don't forget to restart your services.

---

## Using CArrays

### Creating CArrays

Let's create two CArrays using the `Identity` initializer:

```php
$a = CArray::identity(2);
$b = CArray::identity(4);
print_r($a);
print_r($b);
```
```php
CArray Object
(
    [uuid] => 0
    [x] => 2
    [y] => 2
)
CArray Object
(
    [uuid] => 1
    [x] => 4
    [y] => 4
)
```
It sounds strange, but calm down! You will not be able to view your array using
`print_r` because CArrays are not PHP arrays. It's just pointers to memory, to view 
your array you'll need to convert it to PHP Array:

### Converting CArrays to PHP Arrays

Remember that this may require considerable time depending on the size of your CArray. Try performing all operations 
before converting to a PHP Array, and only, if needed of course.

```php
$php_array = CArray::toArray($a);
print_r($php_array);
```
```php
Array
(
    [0] => Array
        (
            [0] => 1
            [1] => 0
        )

    [1] => Array
        (
            [0] => 0
            [1] => 1
        )

)
```
Now we can see our array and use it with other PHP general libraries.

### Creating from PHP Arrays

You also create CArrays from PHP Arrays, use the static `toArray()` method
to create a CArray from PHP Array:

```php
$a = CArray::fromArray([[0,1],[2,3]]);
print_r(CArray::toArray($a));
```
```php
Array
(
    [0] => Array
        (
            [0] => 0
            [1] => 1
        )

    [1] => Array
        (
            [0] => 2
            [1] => 3
        )

)
```

### Basic Operations

Let's tranpose the CArray (matrix) we created above:

```php
$c = CArray::transpose($a);
print_r(CArray::toArray($c));
```
```php
Array
(
    [0] => Array
        (
            [0] => 0
            [1] => 2
        )

    [1] => Array
        (
            [0] => 1
            [1] => 3
        )

)
```
### Destroying CArrays [IMPORTANT]
After we are done with some CArrays or temporary ones, it's good to
destroy them by calling the `destroy()` static method.

```php
CArray::destroy($a);
CArray::destroy($b);
CArray::destroy($);
```

> In small cases, this may not cause trouble, but in larger scales if you
don't destroy temporary CArrays, they will stay in memory until PHP runtime 
send the shutdown signal.

## How it works?
Internally CArrays are just C structures that can handle multiple arrays of
data.

```C                    
/*************          /*************** /***************
/*  CARRAY   *  ====>   /*   array1d   * /*  double[]   *
/*************          /*************** /***************
                        /*************** /*************** /************
                        /*   array2d   * /*   array1d   * /*  double  *
                        /*************** /*************** /************
                                     ...      
```
A buffer called `MemoryStack` handles all CArrays storage within your PC memory:
```php
/**********************           /*******************
/*   MEMORYSTACK      *           /   CArray UUID 0  *
/* Dynamic Allocated  *   =====>  /*******************
/*     Buffer         *           /*  CArray UUID 1  *
/**********************           /*******************
                                  /*  CArray UUID 2  *
                                  /*******************
                                                   ...
```
CArray talks with PHP frontend using only the `MemoryPointer` object, it's the
`CArray Object` you see returned during use and contains the `uuid` property with
the position of your `CArray` inside the `MemoryStack`

So, when you do operations like `transpose`, the operation itself is only performed
with `C` objects and absolutely no PHP arrays are involved in the process.

That's what makes PHPSci so much faster them PHP Arrays.

# Roadmap [0.1]

## General
- #23  Instantiate CArray instead of using multiple parameters [100%]
- Use LAPACKE included within OpenBLAS. [100%]

## Manipulation
- CArray implements IteratorAggregate for iteration.
- CArray `get` non-static method for data retrieval.

## Math
- **Arithmetics**: `add [100%]`, `subtract [100%]`
- **Element-wise**: `sum [100%]`
- **Exponents**:  `exp [100%]`
- **Logarithms**: `log [100%]`, `log10 [100%]`, `log2 [100%]`, `log1p [100%]`
- **Trigonometric**: `tan [100%]`, `sin [100%]`, `cos [100%]`, `arctan [100%]`, `arcsin [100%]`, `arccos [100%]`
- **Hyperbolic**: `sinh [100%]`, `cosh [100%]`, `tanh [100%]`

## Transformations
See: https://docs.scipy.org/doc/numpy/reference/routines.array-manipulation.html
- **Transpose**: `transpose [100%]`
- **Shape**: `flatten [100%]`, `atleast_1d [100%]`, `atleast_2d [100%]`
- **Property**: `T [100%]`, `flat [100%]`
- **Others**: `unique [50%]`

## Initializers (Matrix Creation)
See: https://docs.scipy.org/doc/numpy-1.13.0/reference/routines.array-creation.html
- **Ones & Zeros**: `eye [100%]`, `identity [100%]`, `ones [100%]`, `ones_like [100%]`, `zeros [100%]`, `zeros_like [100%]`, `full [100%]`, `full_like [100%]`
- **Native PHP**: `fromArray [100%]`
- **Ranges**: `arange [100%]`, `linspace [100%]`, `logspace [100%]`
- **Distributions**: `standard_normal [100%]`

## Linear Algebra
See: https://docs.scipy.org/doc/numpy-1.13.0/reference/routines.linalg.html
- **Products**: `matmul [100%]`, `inner [100%]`
- **Decompositions**: `svd [100%]`
- **Eigenvalues**: `eig [100%]`, `eigvals [100%]`
- **Linear Equations**: `solve [100%]`
- **Inverse**: `inv [100%]`
- **Others**: `norm [100%]`, `cond` [100%], `det [100%]`
