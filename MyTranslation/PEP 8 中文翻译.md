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
格指南是有关一致性的重要规约。书写与此风格指南一致的代码很重要，书写与项目风格    
一致的代码更加重要，在一个模块或函数内, 书写风格一致的代码超级重要。所以，风格   
指南并不适用于所有情况，要知道什么时候不一致，这需要你运用自己的智慧进行判断。   
多看一些例子，选择你认为最好的那个，必要的时候要懂得向别人请教。尤其注意：**不   
要为了满足风格指南而破坏与过去代码风格的兼容性！**
>以下情况可以不必考虑风格指南：   
> 1. 即使对于习惯此风格代码的人，应用此风格指南也会使代码的可读性降低。   
> 2. 为了与上下文代码风格一致(当上下文的风格也违背了这个PEP, 可能由于历史原   
> 因), 当然这也是一个规范代码风格的机会(改变上下文的风格)。   
> 3. 有些代码早于此风格指南出现并且没有其他理由要修改这些代码。   
> 4. 代码需要与旧版本的Python代码兼容，但旧版本不支持此风格指南。   

3、代码布局
-------
*(1)缩进*

每个缩进对应四个空格

()、[]或者{}可以隐式的续接一行代码，但要注意垂直对齐，也通过悬挂缩进提高可读性。   
在使用悬挂缩进时，应该注意：参数不能放在首行，后面的缩进要和悬挂缩进有明显区分。
>正确写法：   
>#与括号内部空间对齐
<pre><code>
foo = long_function_name(var_one, var_two,
                         var_three, var_four)
</code></pre>
>#应使用更多缩进，以区别于后边的代码行
<pre><code>
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)
</code></pre>
>#悬挂缩进应多缩进一级（4个空格）
<pre><code>
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)
  other codes
</code></pre>
>错误写法：   
>#参数放在第一行而没有括号内对齐
<pre><code>
foo = long_function_name(var_one, var_two,
    var_three, var_four)
</code></pre>
>#没有多一层缩进以区分后续代码
<pre><code>
def long_function_name(
    var_one, var_two, var_three,
    var_four):
    print(var_one)
</code></pre>
>在分行的情况下，4个空格缩进不是必须的   
>#悬挂缩进可以不是4个空格
<pre><code>
foo = long_function_name(
  var_one, var_two,
  var_three, var_four)
</pre></code>

当if语句的条件部分很长以至于需要将其写成多行时，需要注意，if和单个空格以及左括   
号的组合会使后续行多出一个四空格缩进。