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
多看一些例子，选择你认为最好的那个，必要的时候要懂得向别人请教。尤其注意：*不   
要为了满足风格指南而破坏与过去代码风格的兼容性！*
>以下情况可以不必考虑风格指南：   
> 1. 即使对于习惯此风格代码的人，应用此风格指南也会使代码的可读性降低。   
> 2. 为了与上下文代码风格一致(当上下文的风格也违背了这个PEP, 可能由于历史原   
> 因), 当然这也是一个规范代码风格的机会(改变上下文的风格)。   
> 3. 有些代码早于此风格指南出现并且没有其他理由要修改这些代码。   
> 4. 代码需要与旧版本的Python代码兼容，但旧版本不支持此风格指南。   

3、代码布局
-------
**(1)缩进**

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
号的正好是4空格缩进。这可能会与嵌套在if语句中的代码块产生冲突，这些代码块会自动   
缩进4个空格。本文档不提供确切的做法来解决条件行和if语句嵌套代码块的冲突。一下是   
一些可行的处理方法，但不局限于此：
>#无额外的缩进
<pre><code>
if (this_is_one_thing and
    that_is_another_thing):
    do_something()
</code></pre>
>#通过注释进行区分
<pre><code>
if (this_is_one_thing and
    that_is_another_thing):
    # Since both conditions are true, we can frobnicate.
    do_something()
</code></pre>
>#对条件行增加缩进
<pre><code>
if (this_is_one_thing
        and that_is_another_thing):
    do_something()
</code></pre>
(另请参阅下面的关于在二元运算符之前还是之后换行的讨论。)

多行结构的右括号（包括圆括号，中括号和花括号）可以置于最后一行代码的第一个非空白   
字符下面，如下所示：
<pre><code>
my_list = [
    1, 2, 3,
    4, 5, 6,
    ]
result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
    )
</code></pre>
或者，也可以放在多行结构的下一行的第一个字符位置，如下所示：
<pre><code>
my_list = [
    1, 2, 3,
    4, 5, 6,
]
result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
)
</code></pre>
**（2）“tab”还是空格？**

推荐使用空格控制缩进

tab 只用于与之前的代码保持一致的情况。

Python3 不允许混合使用 tab 和空格控制缩进。

Python2 中混合使用tab和空格缩进的代码应改成只使用空格缩进。

当使用 -t 参数调用 Python2 命令行解释器时，会给出混合使用 tab 和空格的警告。使   
用 -tt 参数会警告升级为错误。我们推荐使用这些参数。

**（3）单行最大长度**

每行最多 79 个字符。

对于具有较少结构限制的长文本块（如Docstrings和注释）每行最多 72 个字符。


调窄编辑器的窗口宽度可以并排打开多个文件，同时也能更好的使用代码审阅工具（在相邻   
两列中显示两个版本的代码）。

大多数工具默认的换行方式破坏了代码可见的结构，让代码变得难于理解，虽然有些工具会   
为换行的代码加上标记，但长度限制就是为了避免编辑器窗口宽度为 80 时糟糕的代码换   
行效果。一些基于 Web 的工具可能根本不会动态换行。

有些团队会喜欢很长的代码行。如果代码只由或主要由他们维护并且也在内部达成一致的   
话，将代码行的长度增加到 80 到 100 个字符都没有什么问题。当然，注释和    
Docstrings仍然维持在72个字符以内。

Python 标准库选择将代码行最大长度限制为 79 个字符，注释或者Docstring限制为   
72个字符。

Python 中首选的换行方式是使用括号括起来隐式的换行。使用圆括号可以将长的代码   
分成多行较短的代码。这种写法要优先于使用 \ 换行。

在某些情况下，也可以使用 \ 换行，比如，当 with 语句很长，隐式换行又不方便，就可   
以使用 \ 。
<pre><code>
with open('/path/to/some/file/you/want/to/read') as file_1, \
     open('/path/to/some/file/being/written', 'w') as file_2:
    file_2.write(file_1.read())
</code></pre>
(请参阅前面有关多行if语句的讨论，进一步思考多行语句的缩进方法。)

另一个类似的情况是 assert 语句。

后续行要正常缩进。

**（4）在二元操作符之前还是之后断行？**

十多年来，在二元操作符之后换行是推荐的风格，但是这会降低代码可读性，一是会使操   
作符分散，二十会使操作符和操作数分离。必须认为的判断应该加上或者减去哪些东西，这   
就增加了人眼的负担。
>#错误写法:   
>操作符离开了操作数
<pre><code>
income = (gross_wages +
          taxable_interest +
          (dividends - qualified_dividends) -
          ira_deduction -
          student_loan_interest)
</pre></code>
为了解决这一可读性问题，数学家和出版商遵循了相反的规约。Donald Knuth 在他的   
《Computers and Typesetting》系列中解释了这一规约。虽然段落中的公式总是在二   
元运算后换行，但显示出来的公式总是在二元运算之前换行。

遵循数学上的传统可以写成可读性更好的代码。
>#正确写法:   
>将操作符与操作数对应
<pre><code>
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
</pre></code>
