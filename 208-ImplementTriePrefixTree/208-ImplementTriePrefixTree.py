# Last updated: 11/25/2026, 3:48:05 PM
class Trie:

    class Node:
        def __init__(self):
            self.child: list[Node] = [None] * 26
            self.is_end: bool = False

    def __init__(self):
        self.root: Node = self.Node()

    def insert(self, word: str) -> None:
        
        i: int = 0
        n: int = len(word)
        trav: Node = self.root

        while i < n:
            chInd = ord(word[i]) - ord('a')

            if trav.child[chInd] == None:
                trav.child[chInd] = self.Node()
            
            trav = trav.child[chInd]

            i += 1
        
        trav.is_end = True


    def search(self, word: str) -> bool:
        
        i: int = 0
        n: int = len(word)
        trav: Node = self.root

        while i < n:
            chInd = ord(word[i]) - ord('a')

            if trav.child[chInd] == None:
                return False
            
            trav = trav.child[chInd]

            i += 1
        
        return trav.is_end

    def startsWith(self, prefix: str) -> bool:
        
        i: int = 0
        n: int = len(prefix)
        trav: Node = self.root

        while i < n:
            chInd = ord(prefix[i]) - ord('a')

            if trav.child[chInd] == None:
                return False
            
            trav = trav.child[chInd]

            i += 1
        
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)