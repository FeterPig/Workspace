import java.util.HashMap;
import java.util.Map;

public class Library {
    private final Map<String, Book> bookStore;

    public Library() {
        bookStore = new HashMap<String, Book>();
    }

    public void addBook(Book book) {
        bookStore.put(book.getIsbn(), book);
    }

    public Book findBookByISBN(String isbn) {
        return bookStore.get(isbn);
    }

    public boolean borrowBook(String isbn) {
        Book book = findBookByISBN(isbn);

        if (book != null && !book.getIsBorrowed()) {
            book.setIsBorrowed(true);
            return true;
        }
        return false;
    }
}