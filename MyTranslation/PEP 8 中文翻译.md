PEP 8--Python代码风格指南
======

1、引言
---
本文档给出了Python编码规约，主要Python发行版中的标准库即遵守该规约。对于C代码   
风格的Python程序，请参阅配套的C代码风格指南。本文档和PEP257（文档字符串规约）   
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

每个缩进级别对应四个空格

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

对于具有较少结构限制的长文本块（如文档字符串和注释）每行最多 72 个字符。


调窄编辑器的窗口宽度可以并排打开多个文件，同时也能更好的使用代码审阅工具（在相邻   
两列中显示两个版本的代码）。

大多数工具默认的换行方式破坏了代码可见的结构，让代码变得难于理解，虽然有些工具会   
为换行的代码加上标记，但长度限制就是为了避免编辑器窗口宽度为 80 时糟糕的代码换   
行效果。一些基于 Web 的工具可能根本不会动态换行。

有些团队会喜欢很长的代码行。如果代码只由或主要由他们维护并且也在内部达成一致的   
话，将代码行的长度增加到 80 到 100 个字符都没有什么问题。当然，注释和文档字符串   
仍然维持在72个字符以内。

Python 标准库选择将代码行最大长度限制为 79 个字符，注释或者文档字符串限制为   
72 个字符。

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
在 Python 代码中，只要前后保持一致，在二元操作符之前或之后换行都可以。对于新的   
代码，建议使用 Knuth 推荐的风格。

**（5）空行**

顶级函数和类的定义前后空两行。

类内部的方法定义前后空一行。

可以使用额外的空白行来分隔相关函数组。一系列相关的单行函数之间的空白行可以省略   
（比如匿名函数）。

在函数内部可以使用空白行来保守的分割逻辑块。

Python 将 Ctrl + L 换页符作为空格，但许多工具仍将它当作换页符，所以你可以用   
这种方法把代码中的相关部分放在一页。需要注意的是，一些编辑器和基于 Web 的代码   
阅读器不会把 Ctrl + L 当作换页符处理，并且在该位置会显示另外的字符。

**（6）源文件编码**

当前主要的 Python 发行版本一般使用 utf-8 编码，在 Python2 中则使用 ASCII    
编码。

Python2 使用 ASCII ，Python3 使用 utf-8 编码，这在文件中不需要进行编码声明   

在标准库中，不使用非默认编码，除非出于测试目的。当注释或文档字符串中使用的作者名   
包含非 ASCII 字符，也可以使用非默认编码。其他情况，建议使用转义字符将非 ASCII    
字符包含于字面中。

对Python3 和更高版本的标准库有一下规定（详见 PEP 3131）：Python 标准库中的所   
有标识符均为 ASCII 编码并且尽可能使用英文单词。某些情况也可以使用非英文的缩写和   
术语。另外，字符串字面和注释也必须使用 ASCII 字符。以下情况例外：测试非 ASCII    
字符；作者姓名。作者姓名如果不再拉丁字母表中（latin-1, ISO/IEC 8859-1 字符集），   
必须改为基于此字母表的音译。

我们鼓励全球用户的开源项目遵循以上规约。

**（7）Import**

导入语句应该单独放到一行，如下：
>正确写法：
<pre><code>
import os
import sys
</code></pre>
>错误写法：
<pre><code>
import sys, os
</code></pre>
这种方式也可以：
<pre><code>
from subprocess import Popen, PIPE
</code></pre>
导入语句一般放在文件开头，在模块注释和文档字符串之后，模块全局变量和常量之前。

>注意分组导入，并遵循一下顺序：   
>   1. 导入标准库
>   2. 导入相关的第三方包
>   3. 导入本地应用或包
>不同的组应使用空行分隔

推荐绝对路径导入方式，通常这样更有可读性，并且当导入系统配置错误时表现更好（至少   
可以提供更好的错误提示信息），比如包里的文件路径有以 sys.path 结尾的。
<pre><code>
import mypkg.sibling
from mypkg import sibling
from mypkg.sibling import example
</code></pre>
然而，清晰的相对路径导入的方式也可以接受，特别是当包的路径比较复杂，使用绝对路径   
导入方式没有必要，并且那样会使代码显得冗杂。
<pre><code>
from . import sibling
from .sibling import example
</code></pre>
标准库的代码一般没有复杂的包结构，并且使用绝对路径的导入方式。

不能使用隐式的相对路径导入，这在 Python3 中已经被移除。

当从包含类的模块中导入类时，可以用以下写法：
<pre><code>
from myclass import MyClass
from foo.bar.yourclass import YourClass
</code></pre>
如果这种写法导致和本地命名空间冲突，则改为：
<pre><code>
import myclass
import foo.bar.yourclass
</code></pre>
这样，要在本地使用 *myclass.MyClass* 或者 *foo.bar.yourclass.YourClass*

避免使用通配符的方式导入（*from <module> import \**），因为这样不能说明命名   
空间中有哪些名称，并且这样会干扰读者和许多自动化工具。有一种情况可以使用通配符方   
式导入，就是发布一个内部接口作为公共的 API （比如，使用可选的加速模块中的定于覆   
盖纯 Python 实现的接口，预先无法知晓具体哪些定义将被覆盖）。

当使用这种方式重新发布名称时，指南后面关于公共和内部接口的部分仍然适用。

**（8）模块级双下划线命名**

模块级的双下划线名称（即在名称的开始和结尾处都有两条下划线）如__all__，   
__author__，__version__ 等，应该写在文档字符串之后，除 *from __future__*    
的任何导入语句之前。Python 要求在模块中 *future-imports* 语句要放在除文档字符   
串外的任何其他代码之前。
>比如：
<pre><code>
"""This is the example module.

This module does stuff.
"""

from __future__ import barry_as_FLUFL

__all__ = ['a', 'b', 'c']
__version__ = '0.1'
__author__ = 'Cardinal Biggles'

import os
import sys
</code></pre>

4、字符串引用
=====
在 Python 中，单引号字符串和双引号字符串是一样的。本 PEP 文档在这一点上不做要求，   
选用一种并坚持下去就好。当字符串本身包含单引号或者双引号时，那就选用未包涵的来表达   
字符串














网上Down来终觉浅，绝知此事要躬行。前后耗费两天时间翻译了 Python 编程语言的官方代码风格指南，
译文已发布到 Github 上，有需要者可以参阅。初次尝试翻译官方英文文档，距离“信、达、雅”的翻译至
高境界还差十万八千里，译文多有不足之处，还望批评指正。以下为译文链接：
https://github.com/kernellmd/MyProjects/blob/master/MyTranslation/PEP%208%20%E4%B8%AD%E6%96%87%E7%BF%BB%E8%AF%91.md