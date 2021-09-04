package com.zhou.controller;

import com.zhou.pojo.Books;
import com.zhou.service.BookService;
import org.apache.ibatis.annotations.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@Controller
@RequestMapping("/book")
public class BookController {
//    controller调用service层
    @Autowired
    @Qualifier("BookServiceImpl")
    private BookService bookService;
//    查询全部书籍，并且返回书籍页面显示
    @RequestMapping("/allBook")
    public String queryAllBooks(Model model){
        List<Books> books = bookService.queryAllBooks();
        model.addAttribute("books",books);
        return "allBook";
    }

//    跳转到增加书籍页面
    @RequestMapping("/toAddBook")
    public String toAddBook(){
        return "addBook";
    }

//    添加书籍请求
    @RequestMapping("/addBook")
    public String addBook(Books books){
        System.out.println(books);
        bookService.addBook(books);
        return "redirect:/book/allBook";
    }

//    跳转到修改页面
    @RequestMapping("/toUpdateBook")
    public String toUpdatePage(int id, Model model){
        Books books = bookService.queryBookById(id);
        model.addAttribute("QBook",books);
        return "updateBook";
    }


//   修改书籍
    @RequestMapping("/updateBook")
    public String updateBook(Books books){
        System.out.println(books);
        bookService.updateBook(books);
        return "redirect:/book/allBook";
    }

//    删除书籍
    @RequestMapping("/deleteBook/{bookId}")
    public String deleteBook(@Param("BookId") int id){
        bookService.deleteBookById(id);
        return "redirect:/book/allBook";
    }
}
