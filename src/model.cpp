#include "model.h"


/*!
 *
 * Model class Constructor
 *
 */

Model::Model(int i, int f, int s){
    this->initial = i;
    this->final = f;
    this->step = s;
}


/*!
 *
 * Model class destructor
 *
 */

Model::~Model(){
    this->MyFlows.clear();
    this->MyFlows.clear();
}


/*!
 *
 * Model class Attribution operator
 * \return Pointer for object class
 *
 */

Model &Model::operator=(const Model &m)
{
    if( &m != this ) {

        for (auto i = this->MyFlows.begin(); i < this->MyFlows.end(); ++i) {
            delete (*i);
        }
        for (auto i = this->MySystems.begin(); i < this->MySystems.end(); ++i) {
            delete (*i);
        }

        auto j = m.MyFlows.begin();
        for (auto i = this->MyFlows.begin(); i < this->MyFlows.end(); ++i) {
            *i = *j;
            ++j;
        }
        auto k = m.MySystems.begin();
        for (auto i = this->MySystems.begin(); i < this->MySystems.end(); ++i) {
            *i = *k;
            ++k;
        }
    }
    return *this;

}

/*!
 *
 * Model class copy operator
 *
 */

Model::Model(Model &m)
{

    for (auto i = this->MyFlows.begin(); i < this->MyFlows.end(); ++i) {
        delete (*i);
    }
    for (auto i = this->MySystems.begin(); i < this->MySystems.end(); ++i) {
        delete (*i);
    }

    auto j = m.MyFlows.begin();
    for (auto i = this->MyFlows.begin(); i < this->MyFlows.end(); ++i) {
        *i = *j;
        ++j;
    }
    auto k = m.MySystems.begin();
    for (auto i = this->MySystems.begin(); i < this->MySystems.end(); ++i) {
        *i = *k;
        ++k;
    }
}


/*!
 *
 * Method define the model execution
 *
 */

void Model::Execute()
{
    double ValueSystemIn, Var, ValueSystemInNew, ValueSystemOutNew;

    for (int i = initial+1;i<=final;i+=step) {

        int j = 0;
        for (auto it = this->MyFlows.begin(); it!=this->MyFlows.end(); ++it) {

            //Recuperar o valor atual do sistema de entrada
            ValueSystemIn = (*it)->getSystemIn()->getValue();

            //Recuperar o novo valor do sistema de entrada
            ValueSystemInNew = (*it)->getSystemIn()->getTempValue();

            //Recuperar o novo valor do sistema de saída
            ValueSystemOutNew = (*it)->getSystemOut()->getTempValue();

            //Definir o valor valor de entrada no fluxo
            (*it)->setValue(ValueSystemIn);

            //Executar o fluxo
            Var = (*it)->Execute();

            //Atualizar o novo valor no sistema de entrada
            ValueSystemInNew -= Var;
            (*it)->getSystemIn()->setTempValue(ValueSystemInNew);

            //Atualizar o novo valor no sistema de saída
            ValueSystemOutNew += Var;
            (*it)->getSystemOut()->setTempValue(ValueSystemOutNew);

            j++;
        }

        for (auto it = this->MySystems.begin(); it!=this->MySystems.end(); ++it) {
            (*it)->setValue((*it)->getTempValue());
        }
    }
}


/*!
 *
 * Method to get model initial value
 * \return Model initial value
 *
 */

int Model::getInitial() const
{
    return initial;
}

void Model::setInitial(int value)
{
    initial = value;
}

/*!
 *
 * Method to get model final value
 * \return Model final value
 *
 */

int Model::getFinal() const
{
    return final;
}

void Model::setFinal(int value)
{
    final = value;
}

/*!
 *
 * Method to get model step value
 * \return Model step value
 *
 */

int Model::getStep() const
{
    return step;
}

void Model::setStep(int value)
{
    step = value;
}

/*!
 *
 * Method to get the number of systems in the model
 * \return Number of systems in the model
 *
 */

int Model::SizeMySystems()
{
    return int(this->MySystems.size());
}

/*!
 *
 * Method to get the number of flows in the model
 * \return Number of flows in the model
 *
 */

int Model::SizeMyFlows()
{
    return int(this->MyFlows.size());
}


/*!
 *
 * Method to add a flow to the model
 *
 */

void Model::Add(Flow *f)
{
    this->MyFlows.push_back(f);
}

/*!
 *
 * Method to add a system to the model
 *
 */

void Model::Add(System *s)
{
    this->MySystems.push_back(s);
}

/*!
 *
 * Method to print model data
 *
 */

void Model::Report()
{
    for (auto it = this->MyFlows.begin(); it!=this->MyFlows.end(); ++it) {
        cout << (*it)->getName() << "        ";
    }
    for (auto it = this->MySystems.begin(); it!=this->MySystems.end(); ++it) {
        cout << (*it)->getName() << "        ";
    }

    cout << endl;

    for (auto it = this->MyFlows.begin(); it!=this->MyFlows.end(); ++it) {
        (*it)->Execute();
        cout << (*it)->getValue() << "  ";
    }
    for (auto it = this->MySystems.begin(); it!=this->MySystems.end(); ++it) {
        cout << (*it)->getValue() << "  ";
    }

    cout << endl;
}
