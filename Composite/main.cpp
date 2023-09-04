#include <iostream>
#include <string>
#include <list>

class Leaf
{
public:
	Leaf(std::string name) :m_name(name)
	{
	}

	void showStruct(std::string preStr)
	{
		std::cout << preStr << "-" << this->m_name << std::endl;
	}

private:
	std::string m_name;
};

class Composite
{
public:

	Composite(std::string name) :m_name(name)
	{
	}

	void addComposite(Composite* p)
	{
		this->childComposite.push_back(p);
		return;
	}

	void addLeaf(Leaf* l)
	{
		this->childLeaf.push_back(l);
		return;
	}

	void showStruct(std::string preStr)
	{
		std::cout << preStr << "+" << this->m_name << std::endl;
		preStr += " ";

		for (auto leaf : this->childLeaf) {
			leaf->showStruct(preStr);
		}

		for (auto composite : this->childComposite) {
			composite->showStruct(preStr);
		}

		return;
	}

private:
	std::string m_name;
	std::list<Composite*>childComposite;
	std::list<Leaf*>childLeaf;
};

class IFile
{
public:
	virtual void display() = 0;
	virtual int add(IFile* file) = 0;
	virtual int remove(IFile* file) = 0;
	virtual std::list<IFile*>* getChild() = 0;
};

class File :public IFile
{
public:
	File(std::string name) :m_name(name)
	{
	}

	virtual void display() override
	{
		std::cout << m_name << "\n";
	}

	virtual int add(IFile* file) override
	{
		return -1;
	}

	virtual int remove(IFile* file) override
	{
		return -1;
	}

	std::list<IFile*>* getChild() override
	{
		return nullptr;
	}

private:
	std::string m_name;
};

class Directory :public IFile
{
public:
	Directory(std::string name) : m_name(name), m_list(new std::list<IFile*>)
	{
	}

	virtual void display() override
	{
		std::cout << m_name << "\n";
	}

	virtual int add(IFile* file) override
	{
		this->m_list->push_back(file);
		return 0;
	}

	virtual int remove(IFile* file) override
	{
		std::remove(this->m_list->begin(), this->m_list->end(), file);
		return 0;
	}

	virtual std::list<IFile*>* getChild() override
	{
		return this->m_list;
	}

private:
	std::string m_name;
	std::list<IFile*>* m_list;
};

void showTree(IFile* root, int level)
{
	if (root == nullptr) {
		return;
	}

	int i = 0;
	for (i = 0; i < level; i++) {
		printf("\t");
	}

	root->display();

	auto list = root->getChild();
	if (list != nullptr) {
		for (auto file : *list) {
			if (file->getChild() == nullptr) {
				for (i = 0; i < level; i++) {
					printf("\t");
				}
				file->display();
			}
			else {
				showTree(file, level + 1);
			}
		}
	}
}

int main(void)
{
	//Composite* root = new Composite("C://");
	//Composite* c1 = new Composite("Program Files");
	//Composite* c2 = new Composite("Windows");

	//Leaf* l1 = new Leaf("a.txt");
	//Leaf* l2 = new Leaf("b.txt");
	//Leaf* l3 = new Leaf("1.c");
	//Leaf* l4 = new Leaf("2.c");

	//root->addComposite(c1);
	//root->addComposite(c2);
	//c1->addLeaf(l1);
	//c1->addLeaf(l2);
	//c2->addLeaf(l3);
	//c2->addLeaf(l4);

	//root->showStruct("");

	Directory* root = new Directory("c://");
	Directory* d1 = new Directory("program files");
	Directory* d2 = new Directory("windows");

	File* f1 = new File("a.txt");
	File* f2 = new File("b.txt");

	root->add(d1);
	root->add(d2);
	d1->add(f1);
	d2->add(f2);

	auto list = root->getChild();

	showTree(root, 0);
	return 0;
}