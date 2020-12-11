template <class T>
void BinaryTree<T>::deleteData(Position &pos)
{
  if (root == nullptr or pos == nullptr)
  {
    throw Exception("Posicion invalida, deleteData");
  }

  if (isLeaf(pos))
  {
    delete pos;
    pos = nullptr;
  }
  else
  {
    // cerr << "\nasd\n";
    Position replacementPos;
    if (pos->getLeft() != nullptr)
    {
      replacementPos = getHighest(pos->getLeft());
      // if (pos->getLeft() != replacementPos)
      // {
      //   pos->setLeft(pos->getLeft()->getLeft());
      // }
      // else
      // {
      //   pos->setLeft(pos->getLeft());
      // }
    }
    else
    {
      // cerr << "correct";
      replacementPos = getLowest(pos->getRight());
      // if (pos->getRight() == replacementPos)
      // {
      //   pos->setRight(pos->getRight()->getRight());
      // }
      // else
      // {
      //   pos->setRight(pos->getRight());
      // }
    }

    pos->setData(replacementPos->getData());
    delete replacementPos;
    replacementPos = nullptr;
  }
}