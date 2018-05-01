PEP 8 -- Python 代码风格指南
======

1、引言
---
本文档给出了 Python 编码规约，主要 Python 发行版中的标准库即遵守该规约。对于   
C 代码风格的 Python程序，请参阅配套的 C 代码风格指南。

本文档和 PEP 257（文档字符串规约）是根据 Guido 的 Python 风格指南一文改编的，   
其中还增加了 Barry 提出的一些风格指南。

风格指南并非一成不变，它本身也在不断发展，过去的惯例会因语言本身的变化而过时。

许多项目有自己的编码风格，在发生冲突时，这类项目的风格指南应优先考虑。

2、固执己见必成心灵之魔
----
Guido认为：代码被阅读之频繁远甚于其被编写。所以，这里提供的准则旨在提高代码的可读   
性并使其在各种Python代码中保持一致。如PEP20所述，“可读性至关重要！”。

风格指南是有关一致性的重要规约。书写与此风格指南一致的代码很重要，书写与项目风格一   
致的代码更加重要，在一个模块或函数内, 书写风格一致的代码超级重要。

所以，风格指南并不适用于所有情况，要知道什么时候不一致，这需要你运用自己的智慧进   
行判断。多看一些例子，选择你认为最好的那个，必要的时候要懂得向别人请教。尤其注意：   
__不要为了满足风格指南而破坏与过去代码风格的兼容性！__
>以下情况可以不必考虑风格指南：   
>1. 即使对于习惯此风格代码的人，应用此风格指南也会使代码的可读性降低。   
>2. 为了与上下文代码风格一致(可能由于历史原因，上下文的风格也违背了本指南)，   
>当然这也是一个规范代码风格的机会(通过改变上下文的风格)。   
>3. 有些代码早于此风格指南出现并且没有其他理由要修改这些代码。   
>4. 代码需要与旧版本的Python代码兼容，但旧版本不支持此风格指南。   

3、代码布局
-------
**(1)缩进**

每级缩进对应四个空格

()、[]或者{}可以隐式的换行，三种括号所包裹的代码要么垂直对齐，要么悬挂缩进。当使   
用悬挂缩进时，应该注意：参数不能放在首行，续行要再缩进一级以便和后边的代码区别开。   
>正确写法：   
>#与左括号对齐（垂直对齐写法）
<pre><code>
foo = long_function_name(var_one, var_two,
                         var_three, var_four)
</code></pre>
>#悬挂缩进
<pre><code>
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)
</code></pre>
>#如果后边有代码行，悬挂缩进增加一级
<pre><code>
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)
</code></pre>
>错误写法：   
>#参数放在第一行而没有垂直对齐
<pre><code>
foo = long_function_name(var_one, var_two,
    var_three, var_four)
</code></pre>
>#后边有代码行时没有增加缩进
<pre><code>
def long_function_name(
    var_one, var_two, var_three,
    var_four):
    print(var_one)
</code></pre>
>对于续行来说，4个空格的缩进规则可以不必遵守   
>#可以不采用是4个空格的缩进方法
<pre><code>
foo = long_function_name(
  var_one, var_two,
  var_three, var_four)
</pre></code>

当if语句的条件部分很长以至于需要将其写成多行时，需要注意，if和单个空格以及左括号   
正好是4个空格缩进，这可能与嵌套在if语句中的代码块产生冲突。本文档不提供确切的方法　　　
来解决条件行和if语句的嵌套代码块的冲突。以下是一些可行的处理方法，但不必局限于此：　　　
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
>#对条件行的续行增加缩进
<pre><code>
if (this_is_one_thing
        and that_is_another_thing):
    do_something()
</code></pre>
(另请参阅下面的关于在二元运算符之前还是之后换行的讨论。)

多行结构的右括号（包括圆括号，中括号和花括号）可以置于最后一行代码的第一个非空白字   
符下面，如下所示：
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
**（2）“Tab”还是空格？**

推荐使用空格控制缩进

tab 只用于与之前的代码保持一致的情况。

Python3 不允许混合使用 tab 和空格控制缩进。

Python2 中混合使用 tab 和空格缩进的代码应改成只使用空格缩进。

当使用 -t 选项调用 Python2 命令行解释器时，会给出混合使用 tab 和空格的警告。使   
用 -tt 选项时，这些警告会变为错误。我们推荐使用这些选项。

**（3）单行最大长度**

每行最多 79 个字符。

对于具有较少结构限制的长文本块（如文档字符串和注释）每行最多 72 个字符。


限制编辑器的窗口宽度可以在屏幕上并排打开多个文件，同时也能更好地使用代码审阅工具   
（在相邻两列中显示两个版本的代码）。

大多数工具默认的换行方式破坏了代码可见的结构，让代码变得难于理解。在窗口大小为   
80 的编辑器中，即使换行的代码会在最后一列被打上标记，为了避免自动换行也需要限制每   
行字符长度。一些基于 Web 的工具可能根本不会自动换行。

有些团队会喜欢很长的代码行。如果代码只由或主要由他们维护并且也在内部达成一致的话，   
将代码行的长度增加到 80 到 100 个字符（实际上最大行长是 99 个字符）都没有什么问   
题。当然，注释和文档字符串仍然维持在72个字符以内。

Python 标准库比较保守，选择将代码行最大长度限制为 79 个字符，注释或者文档字符串   
限制为 72 个字符。

Python 中首选的换行方式是使用括号括起来隐式地换行。使用括号可以将长的代码行分成多   
个较短行。这种写法要优先于使用 \ 换行。

在某些情况下，也可以使用 \ 换行，比如，当 with 语句很长，隐式换行又不方便，就可   
以使用 \ 。
<pre><code>
with open('/path/to/some/file/you/want/to/read') as file_1, \
     open('/path/to/some/file/being/written', 'w') as file_2:
    file_2.write(file_1.read())
</code></pre>
(参阅前面有关多行 if 语句的讨论，进一步考虑这里 with 语句的缩进。)

另一个这样的例子是 assert 语句。

要确保续行的缩进适当。

**（4）在二元运算符之前还是之后换行？**

长期以来，一直推荐的风格是在二元运算符之后换行，但是这会影响代码可读性，一是会使运   
算符分散在屏幕的不同列上，二是会使每个运算符留在前一行，并远离操作数分离。必须人为   
的判断应该加上或者减去哪些东西，这就增加了人眼的负担。
>#错误写法:   
>运算符远离操作数
<pre><code>
income = (gross_wages +
          taxable_interest +
          (dividends - qualified_dividends) -
          ira_deduction -
          student_loan_interest)
</pre></code>
为了解决这一可读性问题，数学家和出版商遵循了相反的规约。Donald Knuth 在他的   
《Computers and Typesetting》丛书中解释了这一规约。“虽然段落中的公式总是在二   
元运算符后换行，但显示公式时总是在二元运算符之前换行。”

遵循数学上的传统可以写出可读性更好的代码。
>#正确写法:   
>更容易匹配运算符与操作数
<pre><code>
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
</pre></code>
在 Python 代码中，只要前后保持一致，在二元操作符之前或之后换行都可以。对于新写的   
代码，建议使用 Knuth 推荐的风格。

**（5）空行**

顶级函数和类的定义前后空两行。

类内部的方法定义前后空一行。

可以使用额外的空行（尽量少）来分隔相关函数组。一系列相关的仅占一行的函数之间的空白   
行可以省略（比如一系列虚函数）。

在函数内部可以使用空行（尽量少）来分割逻辑上的代码块。

Python 将 Ctrl + L 换页符作为空格，但许多工具将它当作分页符，所以你可以用这种方   
法把文件中的相关代码放在一页。注意：一些编辑器和基于 Web 的代码阅读器可能不会把   
 Ctrl + L 当作换页符处理，并且在该位置会显示其他的字符。

**（6）源文件编码**

当前核心的 Python 发行版本一直使用 utf-8 编码，在 Python2 中则使用 ASCII    
编码。

Python2 使用 ASCII ，Python3 使用 utf-8 编码，这在文件中不需要进行编码声明   

在标准库中，不使用非默认编码，除非出于测试目的。当注释或文档字符串中使用的作者名   
包含非 ASCII 字符，也可以使用非默认编码。其他情况下，若要在字符串中包含非 ASCII    
数据，建议使用转义字符 `\x` `\u` `\U` `\N` 。

对 Python3 及更高版本的标准库有以下规定（详见 PEP 3131）：Python 标准库中的所   
有标识符均为 ASCII 编码并且尽可能使用英文单词。某些情况也可以使用非英文的缩写和   
术语。另外，字符串字面量和注释也必须使用 ASCII 字符。以下情况例外：
*  测试非 ASCII 字符的特性
*  作者姓名。作者姓名如果不在拉丁字母表中（latin-1, ISO/IEC 8859-1 字符集），   
必须给出基于此字母表的音译名。

我们鼓励全球受众的开源项目采用规约。

**（7）导入**

* 导入语句应该分开写，而不是都放到一行，例如：
  >正确写法：
  <pre><code>
  import os
  import sys
  </code></pre>
  >错误写法：
  <pre><code>
  import sys, os
  </code></pre>
  这种写法也可以：
  <pre><code>
  from subprocess import Popen, PIPE
  </code></pre>
* 导入语句一般放在文件开头，在模块注释和文档字符串之后，模块全局变量和常量之前。

  >注意分组导入，并遵循一下顺序：   
  >>1. 标准库导入
  >>2. 相关的第三方包导入
  >>3. 本地应用或库的特定导入
  >
  >不同的组应使用空行分隔

* 推荐绝对路径导入方式，通常这样更有可读性，在系统配置错误时的情况下（比如包里的文   
件路径有以 sys.path 结尾的。），也会表现得更好（至少会给出更好的错误提示信息）：
  <pre><code>
  import mypkg.sibling
  from mypkg import sibling
  from mypkg.sibling import example
  </code></pre>
  然而，清晰的相对路径导入方式也可以接受，特别是当包的结构比较复杂，使用绝对路径导   
入方式没有必要，反而会使代码显得冗杂。
  <pre><code>
  from . import sibling
  from .sibling import example
  </code></pre>
  标准库的代码没有复杂的包结构，并且一直使用绝对路径的导入方式。

  不能使用隐式的相对路径导入，这在 Python3 中已经被移除。

* 当从包含类的模块中导入类时，可以使用以下写法：
  <pre><code>
  from myclass import MyClass
  from foo.bar.yourclass import YourClass
  </code></pre>
  如果这种写法导致和本地命名空间冲突，则改为：
  <pre><code>
  import myclass
  import foo.bar.yourclass
  </code></pre>
  然后使用`myclass.MyClass` 或者`foo.bar.yourclass.YourClass`

* 避免使用通配符的方式导入（`from <module> import *`），因为这会使当前命名空间   
中的名称含义不清晰，给读者和许多自动化工具造成困扰。有一种情况正当使用通配符导入的   
情形，就是将一个内部接口重新发布作为公共 API （比如，使用可选的加速模块中的定义覆   
盖纯 Python 实现的接口，预先无法知晓具体哪些定义将被覆盖）。

  当使用这种方式重新发布名称时，指南后面关于公共和内部接口的部分仍然适用。

**（8）模块级双下划线名称**

模块级的双下划线名称（即在名称的开始和结尾处都有两条下划线）如__all__，   
__author__，__version__ 等，应该写在文档字符串之后，除`from __future__`外其    
他导入语句之前。Python 要求在模块中`future-imports`语句要放在除文档字符串外的任   
何其他代码之前。
>例如：
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
选用一种并坚持下去就好。当字符串本身包含单引号或者双引号时，那就选用未包含的引号来   
表示字符串，这样可以避免使用`\`，代码也更易读。

如果使用三引号形式的字符串，则用双引号`"`组成三引号`"""`，这样可以和 PEP 257 中   
的文档字符串规约保持一致。

5、表达式和语句中的空格
====
**（1）一些痛点**

以下情形中要避免使用过多空格：
* 括号内部紧挨括号的地方，包括圆括号、方括号和花括号
  >正确写法：
  <pre><code>
  spam(ham[1], {eggs: 2})
  </code></pre>
  >错误写法：
  <pre><code>
  spam( ham[ 1 ], { eggs: 2 } )
  </code></pre>
* 逗号后面跟着右括号
  >正确写法：
  <pre><code>
  foo = (0,)
  </code></pre>
  >错误写法：
  <pre><code>
  bar = (0, )
  </code></pre>
* 逗号，分号，和冒号之前
  >正确写法：
  <pre><code>
  if x == 4: print x, y; x, y = y, x
  </code></pre>
  >错误写法：
  <pre><code>
  if x == 4 : print x , y ; x , y = y , x
  </code></pre>
* 然而，在切片操作中，冒号作为二元运算符，两边应该具有相同数目的空格（可将其视作   
最低优先级的运算符）。在扩展切片操作中，两个冒号左右两边的空格数都应该相等。当然，   
如果切片操作省略了参数，那么空白也应该省略。
  >正确写法：
  <pre><code>
  ham[1:9], ham[1:9:3], ham[:9:3], ham[1::3], ham[1:9:]
  ham[lower:upper], ham[lower:upper:], ham[lower::step]
  ham[lower+offset : upper+offset]
  ham[: upper_fn(x) : step_fn(x)], ham[:: step_fn(x)]
  ham[lower + offset : upper + offset]
  </code></pre>
  >错误写法：
  <pre><code>
  ham[lower + offset:upper + offset]
  ham[1: 9], ham[1 :9], ham[1:9 :3]
  ham[lower : : upper]
  ham[ : upper]
  </code></pre>
* 函数调用时，包裹参数列表的左括号之前
  >正确写法：
  <pre><code>
  spam(1)
  </code></pre>
  >错误写法：
  <pre><code>
  spam (1)
  </code></pre>
* 为了对齐，在赋值号或者其他运算符前后加多个空格
  >正确写法：
  <pre><code>
  x = 1
  y = 2
  long_variable = 3
  </code></pre>
  >错误写法：
  <pre><code>
  x             = 1
  y             = 2
  long_variable = 3
  </code></pre>

**（2）其他建议**

* 避免任何行末空格，因为通常不可见，它们容易让人困惑。例如，`\`后跟一个空格和一个   
新行，`\`将不会被当作续行符。有些编辑器可以自动去除行末空格。对于这种情况，许多项   
目（如CPython本身）会用钩子做提交前检查。

* 这些二元运算符两边通常保留一个空格：赋值运算符（=），增强的复制运算符（+=，-=等）   
关系运算符（==，<，>，!=，<=，>=，in，not in，is，is not），布尔运算符（and，   
or，not）。

* 如果混用了不同优先级的运算符，可以考虑在低优先级运算符两边增加空格。但不要超过一   
个，并且要保持二元运算符两边的空格数量相同。
  >正确写法
  <pre><code>
  i = i + 1
  submitted += 1
  x = x*2 - 1
  hypot2 = x*x + y*y
  c = (a+b) * (a-b)
  </code></pre>
  >错误写法
  <pre><code>
  i=i+1
  submitted +=1
  x = x * 2 - 1
  hypot2 = x * x + y * y
  c = (a + b) * (a - b)
  </code></pre>
* 当表示关键字参数或者默认参数时，等号两边不加空格
  >正确写法
  <pre><code>
  def complex(real, imag=0.0):
    return magic(r=real, i=imag)
  </code></pre>
  >错误写法
  <pre><code>
  def complex(real, imag = 0.0):
    return magic(r = real, i = imag)
  </code></pre>
* 函数注释中的冒号遵循一般的加空格的规则，如果有箭头，要在其两边加空格。（更多信息   
请见下面的函数注释。）
  >正确写法
  <pre><code>
  def munge(input: AnyStr): ...
  def munge() -> AnyStr: ...
  </code></pre>
  >错误写法
  <pre><code>
  def munge(input:AnyStr): ...
  def munge()->PosInt: ...
  </code></pre>
* 当组合使用参数注释和参数默认值时，赋值号两边要加空格（但仅对既有空格又有默认值的   
参数成立）。
  >正确写法
  <pre><code>
  def munge(sep: AnyStr = None): ...
  def munge(input: AnyStr, sep: AnyStr = None, limit=1000): ...
  </code></pre>
  >错误写法
  <pre><code>
  def munge(input: AnyStr=None): ...
  def munge(input: AnyStr, limit = 1000): ...
  </code></pre>
* 通常不鼓励使用复合语句（即将多条语句写在一行）
  >正确写法
  <pre><code>
  if foo == 'blah':
    do_blah_thing()
  do_one()
  do_two()
  do_three()
  </code></pre>
  >最好不要这样写
  <pre><code>
  if foo == 'blah': do_blah_thing()
  do_one(); do_two(); do_three()  
  </code></pre>
* 然而，小型的`if/for/whiel`语句放在一行是可以的。但是有多条分句时不要这样做。也   
要避免无谓的换行！
  >最好不要这样写
  <pre><code>
  if foo == 'blah': do_blah_thing()
  for x in lst: total += x
  while t < 10: t = delay()
  </code></pre>
  >绝对不要这样写
  <pre><code>
  if foo == 'blah': do_blah_thing()
  else: do_non_blah_thing()
  
  try: something()
  finally: cleanup()
  
  do_one(); do_two(); do_three(long, argument,
                             list, like, this)
  
  if foo == 'blah': one(); two(); three()
  </code></pre>

6、何时在末尾加逗号
======
末尾的逗号通常是可选的。但是，在定义单元素元组时是必须的（而且在 Python2 中，逗   
号对 print 语句有特殊语义）。清楚起见，建议使用括号括起来（在技术上是冗余的）。   
>正确写法
<pre><code>
FILES = ('setup.cfg',)
</code></pre>
>也可以，但是难于理解
<pre><code>
FILES = 'setup.cfg',
</code></pre>

当使用版本控制系统时，在将来有可能扩展的值和参数列表或者导入条目的末尾添加冗余的逗   
号是有好处的。书写模式：每行只写一个值并且加上逗号，在最后的新行写上右括号。但是，   
把逗号和右括号写在同一行毫无意义（除了上面提到的单元素元组）。
>正确写法
<pre><code>
FILES = [
    'setup.cfg',
    'tox.ini',
    ]
initialize(FILES,
           error=True,
           )
</code></pre>
>错误写法
<pre><code>
FILES = ['setup.cfg', 'tox.ini',]
initialize(FILES, error=True,)
</code></pre>

7、注释
=====
和代码相矛盾的注释还不如没有注释。当代码更新时，要优先更改注释，使其保持最新状态。

注释应该是完整的句子。第一个单词首字母要大写，除非是一个小写字母开头的标识符（永远   
不要修改标识符的大小写！）。

块注释通常由完整句子构成的一个或多个段落组成，每个句子都以句号结束。   

在多语句注释中，除了最后一条句子，应当在句尾的句号后面加两个空格。

如果使用英文写作，参考 Strunk 和 White 的著作。

来自非英语国家的 Python 程序员们：请书写英文注释，除非你 120% 确定你所写的代码永   
远不会被不懂你所用语言的人读到。

**（1）块注释**

块注释一般写在对应代码之前，并且和对应代码有同样的缩进级别。块注释以一个 # 和一个   
空格打头（除非注释内的文本也有缩进）。

块注释中的段落用以单个 # 字符开头的空行分隔。

**（2）行内注释**

少用行内注释。

行内注释和代码语句写在同一行，至少以两个空格分隔。并且也以一个 # 和一个空格打头。   

行内注释通常不是必要的，在代码含义很明显时甚至会让人分心。不要有以下写法：
<pre><code>
x = x + 1                 # Increment x
</code></pre>
但有时却是必要的：
<pre><code>
x = x + 1                 # Compensate for border
</code></pre>

**(3)文档字符串**

要写出好的文档字符串（又名“docstrings”），请参阅 PEP 257 。

* 应该为所有的公共模块、函数、类和方法编写文档字符串。文档字符串对于非公共方法不是   
必须的，但是应该留有注释以说明此方法的用途，此注释要放在`def`语句的下一行。

* PEP 257 有好文档字符串规约。尤其注意，多行文档字符串结尾处的`"""`要单独占一行   
例如：
<pre><code>
"""Return a foobang

Optional plotz says to frobnicate the bizbaz first.
"""
</code></pre>
* 对于单行文档字符串，可以把末尾的`"""`放在同一行。

8、命名规约
=====
Python 库的命名规约有些混乱，所以我们无法就此保持完全一致。但我们当前还是有一些值   
得推荐的命名规约。书写新的模块和包（包括第三方框架）时，应当遵循这些标准。但是如果   
现有的库遵循了不同的代码风格，那么应该保持内部代码的一致性。

**（1）首要原则**

对用户可见的公共部分 API ，其名称应该反应出其用途而不是实现。

**（2）描述：命名风格**

不同的命名风格有很多，最好能从应用他们的代码而识别出对应命名风格。

注意区别以下命名风格：   
* b（单个小写字符）
* B（单个大写字符）
* lowercase（小写单词）
* lower_case_with_underscores（下划线连接的小写单词）
* UPPERCASE（大写单词）
* UPPER_CASE_WITH_UNDERSCORES（下划线连接的大写单词）
* CapitalizedWords（也叫做CapWords或CamelCase – 因为单词首字母大写看起来像驼   
峰而得名）有时也被称为 StudlyCaps 。

  注意：当使用首字母缩略词时，将缩略词的所有字母大写。因此HTTPServerError的写法   
比HttpServerError更好。
* mixedCase（和CapitalizedWords的不同之处是最开始的字母要小写！）
* Capitalized_Words_With_Underscores（真丑！）

还有的命名风格用简短的唯一前缀将相关的名称写在一组。这在 Python 中不常用，但完整   
起见，这里点出来。例如，`os.stat()`函数会返回一个元组，其中包含`st_mode`，   
`st_size`，` st_mtime`等名称。这样做是为了强调和 POSIX 系统调用结构之间的关系，   
让程序员更熟悉。

X11 库中的公共的函数名都以 X 开头。在 Python 中，一般认为这种风格没什么必要，因   
为属性和方法名都以对象名为前缀，函数名以模块名为前缀。

另外，以下用下划线开始或结尾的特殊形式也是被认可的（与其他规约结合使用）：   
* _single_leading_underscore：内部使用的弱标识。例如，`from M import *`语句   
并不会导入以下划线开头的对象。
* single_trailing_underscore_：以单下划线结尾避免和 Python 关键字冲突。例如：
<pre><code>
Tkinter.Toplevel(master, class_='ClassName')
</code></pre>
* __double_leading_underscore：以双下划线开头的风格命名类属性时触发命名修饰   
（在 FooBar 类内部， __boo 命名会被修饰成_Foo__boo；见以下）。
* __double_leading_and_trailing_underscore__：以双下划线开头和结尾的命名风   
格表示“魔术”对象或属性，存在于用户控制的命名空间中。例如：`__init__`，   
`__import__ `或者 `__file__`。除了按文档描述来使用这些命名，不要私自使用。

