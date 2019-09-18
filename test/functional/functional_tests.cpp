#include "functional_tests.h"

FuncionalTest::FuncionalTest(){
    this->m = new Model(0, 100, 1);
}

FuncionalTest::~FuncionalTest(){

}

/*!
 * Functional test for simulate exponencial model
 */

TEST_F(FuncionalTest, Exponential) {

    //Instanciar o modelo
    Model *M = new Model(0, 100, 1);

    //Instanciar o fluxo
    ExpFlow *F = new ExpFlow("F");

    //Instanciar o sistema
    System *pop1, *pop2;
    pop1 = new System(100.0, "pop1");
    pop2 = new System(0.0, "pop2");

    //Adicionar o fluxo e os sistemas ao modelo
    M->Add(F);
    M->Add(pop1);
    M->Add(pop2);

    //Conectar os dois sistemas ao fluxo
    F->Conect(pop1, pop2);

    //Executar o modelo
    M->Execute();

    //Verificar o valor final do modelo
    EXPECT_LE(abs(pop1->getValue() - 36.6032), EPSILON);
    EXPECT_LE(abs(pop2->getValue() - 63.3968), EPSILON);
}

/*!
 * Functional test for simulate logistic model
 */

TEST_F(FuncionalTest, Logistic) {

    //Instanciar o modelo
    Model *M = new Model(0, 100, 1);

    //Instanciar o fluxo
    LogFlow *F = new LogFlow("F");

    //Instanciar o sistema
    System *p1, *p2;
    p1 = new System(100.0, "p1");
    p2 = new System(10.0, "p2");

    M->Add(F);
    M->Add(p1);
    M->Add(p2);

    F->Conect(p2, p1);

    M->Execute();

    //Verificar o valor final do modelo
    EXPECT_LE(abs(p1->getValue() - 88.2167), EPSILON);
    EXPECT_LE(abs(p2->getValue() - 21.7833), EPSILON);
}

/*!
 * Functional test for simulate complex model
 */

TEST_F(FuncionalTest, Complex) {
    //Instanciar o modelo
    Model *M = new Model(0, 100, 1);

    ExpFlow *V, *U, *G, *F, *T, *R;
    System *Q1, *Q2, *Q3, *Q4, *Q5;

    F = new ExpFlow("F");
    G = new ExpFlow("G");
    R = new ExpFlow("R");
    T = new ExpFlow("T");
    V = new ExpFlow("V");
    U = new ExpFlow("U");

    Q1 = new System(100.0, "Q1");
    Q2 = new System(0, "Q2");
    Q3 = new System(100.0, "Q3");
    Q4 = new System(0.0, "Q4");
    Q5 = new System(0.0, "Q5");

    M->Add(F);
    M->Add(G);
    M->Add(R);
    M->Add(T);
    M->Add(U);
    M->Add(V);

    M->Add(Q1);
    M->Add(Q2);
    M->Add(Q3);
    M->Add(Q4);
    M->Add(Q5);

    //Conectar os fluxos
    F->Conect(Q1, Q2);
    G->Conect(Q1, Q3);
    R->Conect(Q2, Q5);
    T->Conect(Q2, Q3);
    U->Conect(Q3, Q4);
    V->Conect(Q4, Q1);

    M->Execute();

    //Verificar o valor final do modelo
    EXPECT_LE(abs(Q1->getValue() - 31.8513), EPSILON);
    EXPECT_LE(abs(Q2->getValue() - 18.4003), EPSILON);
    EXPECT_LE(abs(Q3->getValue() - 77.1143), EPSILON);
    EXPECT_LE(abs(Q4->getValue() - 56.1728), EPSILON);
    EXPECT_LE(abs(Q5->getValue() - 16.4612), EPSILON);
}
