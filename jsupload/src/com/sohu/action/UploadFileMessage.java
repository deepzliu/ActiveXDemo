package com.sohu.action;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

/**
 * Servlet implementation class UploadFileMessage
 */
@WebServlet("/UploadFileMessage")
public class UploadFileMessage extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public UploadFileMessage() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/html");
		//设置字符编码为UTF-8，支持汉字显示
		response.setCharacterEncoding("UTF-8");
		
		String jsonp = request.getParameter("callback");
		
		DiskFileItemFactory factory = new DiskFileItemFactory();
		//FileUpload用来解析request文件上传请求  
		ServletFileUpload upload = new ServletFileUpload(factory); 
		String json = "";
		String size = "";
		double fileSize = 0;
		PrintWriter out = response.getWriter();
		try{
			List list = upload.parseRequest(request);
			Iterator iterator = list.iterator();
			while(iterator.hasNext()){
				FileItem fileItem = (FileItem)iterator.next();
				fileSize = fileItem.getSize();
				if(fileSize > 1024 * 1024)
					size = (float)Math.round(fileSize * 100 / (1024 * 1024)) / 100 + "MB";
				else
					size = (float)Math.round(fileSize * 100 / 1024) / 100 + "KB";
				json = "<script type='text/javascript' id='" + jsonp + "'>parent." + jsonp + "({name:'" + fileItem.getName().substring(fileItem.getName().lastIndexOf("\\") + 1) + "',size:'" + size + "',type:'" + fileItem.getContentType() + "'});setTimeout(function(){delete parent." + jsonp + ";var s=document.getElementById('" + jsonp + "');s.parentNode.removeChild(s);},50);</script>";
			}
		}catch(Exception e){
			e.printStackTrace();
		}
		out.print(json);
	}
}
