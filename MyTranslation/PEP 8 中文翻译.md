PEP 8--Python代码风格指南
======

1、引言
---
本文档给出了Python编码规约，主要Python发行版中的标准库即遵守该规约。对于C代码   
风格的Python程序，请参阅配套的C代码风格指南。本文档和PEP257（Docstring规约）   
是根据Guido的Python风格指南一文改编的，其中还增加了Barry提出的一些风格指南。   
风格指南并非一层不变，它本身也在不断发展，过去的惯例会因语言本身的变化而过时。   
许多项目有自己的编码风格，在发生冲突时，这类项目的风格指南应优先考虑。

2、固执己见必成心灵之魔
----
Guido认为：代码被阅读之频繁远甚于其被编写。所以，这里提供的准则旨在提高代码的   
可读性并使其在各种Python代码中保持一致。如PEP20所述，“可读性至关重要！”。风   
格指南是有关一致性的重要规约，然而，项目的一致性、模块和函数的一致性比这更为重   
要。所以，风格指南并不适用于所有情况，要知道什么时候不一致，这需要你运用自己的   
智慧进行判断。多看一些例子，选择你认为最好的那个，必要的时候要懂得向别人请教。   
尤其注意：**不要为了满足风格指南而打破向后兼容性！**
>以下情况可以不必考虑风格指南：   
> 1. 即使对于习惯此风格代码的人，应用此风格指南也会使代码的可读性降低。   
> 2. 要与已存在的代码保持一致，尽管应用此风格可以清除一些混乱的代码。   
> 3. 有关代码早于此风格指南出现并且没有其他理由要修改该代码。   
> 4. 代码需要与旧版本的Python代码兼容，但旧版本不支持此风格指南。   

3、代码布局
-------
*(1)缩进*

每个缩进对应四个空格

()、[]或者{}可以隐式的续接一行代码，但要注意垂直对齐，也通过悬挂缩进提高可读性。   
在使用悬挂缩进时，应该注意：第一行不能有参数，续接的行要缩进。
>正确写法：   
>#与开始的分隔符对齐
<pre><code>
foo = long_function_name(var_one, var_two,
                         var_three, var_four)
</code></pre>
>#应使用更多缩进，以区别于其他代码行
<pre><code>
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)
</code></pre>
>#悬挂缩进后应追加一个空行
<pre><code>
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)

other codes
</code></pre>
>错误写法   
>#参数放在第一行而没有使用垂直对齐
<pre><code>
foo = long_function_name(var_one, var_two,
    var_three, var_four)
</code></pre>
>#续行部分没有进一步缩进
<pre><code>
def long_function_name(
    var_one, var_two, var_three,
    var_four):
    print(var_one)
</code></pre>
>四个空格缩进不是必须的   
>#悬挂缩进可以使用更多空格