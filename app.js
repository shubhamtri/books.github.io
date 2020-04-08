class Book{
  constructor(title,author,isbn){
    this.title=title;
    this.author=author;
    this.isbn=isbn;
  }
}

class UI{
  addBook(book){
   const list=document.getElementById('book-list');
   const tr=document.createElement('tr');
   tr.innerHTML=`
   <td>${book.title}</td>
   <td>${book.author}</td>
   <td>${book.isbn}</td>
   <td><a href="#" class="delete">X</a></td>
   `;
   list.appendChild(tr);

  }
  showErr(msg,color){
   const h6=document.createElement('h6');
   h6.className="alert"
   const con=document.querySelector('.container');
   const heading=document.getElementById('heading');
   h6.appendChild(document.createTextNode(msg));
   h6.style.backgroundColor=color;
   h6.style.color="white";
   con.insertBefore(h6,heading);
   setTimeout(function(){
     document.querySelector('.alert').remove();
   },2000);

  }
  deleteData(target){
    if(target.className==='delete'){
      target.parentElement.parentElement.remove();
      this.showErr("Data removed Succesfully","blue");
    }
  }
  clearData(){
  document.getElementById('title').value='';
  document.getElementById('author').value='';
  document.getElementById('isbn').value='';
  }
}




class Store{
  static getBooks(){
   let books;
   if(localStorage.getItem('books')===null){
     books=[];
   }else{
     books=JSON.parse(localStorage.getItem('books'));
   }
  return books;
  }
  static addBooks(book){
  let books=Store.getBooks();
  books.push(book);
  localStorage.setItem('books',JSON.stringify(books));

  }
  static deleteItem(text){
    let books=Store.getBooks();
    books.forEach(function(book,index){
      if(book.isbn===text){
        books.splice(index,1);
      }
    });
    localStorage.setItem('books',JSON.stringify(books));
  }
  static displayBooks(){
   let books=Store.getBooks();
   books.forEach(book => {
     const ui=new UI;
     ui.addBook(book);
   });
  }
}

////DOM load event
document.addEventListener('DOMContentLoaded',Store.displayBooks());



document.getElementById('book-form').addEventListener('submit',function(e){
  const title=document.getElementById('title').value,
   author=document.getElementById('author').value,
   isbn=document.getElementById('title').value
  const book=new Book(title,author,isbn);
  const ui=new UI;
  // console.log(ui);
  if(title==='' || author==='' || isbn===''){
    ui.showErr('Please Check Your data carefully',"red");
  }else{
   ui.addBook(book);
  ui.showErr('Voilla!!! Data Added Successfully','green');
   
  Store.addBooks(book);

  ui.clearData();

  }
  e.preventDefault();

})

document.getElementById('book-list').addEventListener('click',function(e){
  const ui=new UI;
ui.deleteData(e.target);
Store.deleteItem(e.target.parentElement.previousElementSibling.textContent);
})