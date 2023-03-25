### 一、遗传算法

#### 1、遗传算法的相关术语

1. 染色体（基因链码）
   - 使用遗传算法的时候，需要把问题的每一个编码解出为一个基因链码

2. 适应度
   - 个体对环境的适应程度叫做适应度

#### 2、遗传算法的三种操作

1. 选择操作
   - **个体的适应度越高，其被选择的概率越大**
   - 把每个个体的适应度值`fi`在适应度值之和中所占的比例`fi/∑fi`作为相应的选择概率

2. 交叉操作
   - 遗传算法中选择群体的两个个体，随机地选择一个截断点，把两个基因链码断开处后半部分相互交换，从而产生两个新的个体

(十进制) | 双亲 | 后代 | (十进制)
---|---|---|---
26 | 110/10 | 110/11 | 27
19 | 100/11 | 100/10 | 18

3. 变异操作
   - 随机选取基因链码中的某一位并改变它的值，就可以产生新的个体

(十进制) | 变异前 | 变异后 | (十进制)
---|---|---|---
26 | 110/10 | 111/10 | 30

#### 3、遗传算法函数

`[x, fval] = ga(fun, nvars, A, b, Aeq, beq, lb, ub, nonlcon, options)`

---
### 二、模拟退火算法

#### 1、模拟退火原理

- 与物理退火相似，在退火过程中，使得物体分子在每一温度时，能够有足够的时间找到安顿的位置，随着温度的降低，最终可达到最低能态，此时系统最为安稳

#### 2、模拟退火算法

`[x, fval] = simulannealbnd(fun, x0, lb, ub, options)`
 
---
### 三、粒子群算法

`[x, fval] = particleswarm(fun, x0, lb, ub, options)`
