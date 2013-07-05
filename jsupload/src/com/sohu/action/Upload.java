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
import javax.servlet.http.HttpSession;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.ProgressListener;
import org.apache.commons.fileupload.FileUploadBase.SizeLimitExceededException;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

/**
 * Servlet implementation class Upload
 */
@WebServlet("/Upload")
public class Upload extends HttpServlet {
	private static final long serialVersionUID = 1L;

    /**
     * Default constructor. 
     */   
    public Upload() {
        // TODO Auto-generated constructor stub
    	super();
    }
  
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		//设置字符编码为UTF-8，支持汉字显示
		response.setCharacterEncoding("UTF-8");
		final long MAX_SIZE = 1024 * 1024 * 1024;//设置上传文件最大为1G
		
		//上传文件路径
		String filePath = "e:\\upload\\";
		String tempPath = "e:\\upload\\temp\\";
		
		//jsonp上传
		String jsonp = request.getParameter("callback");
		
		// 实例化一个硬盘文件工厂,用来配置上传组件ServletFileUpload
		DiskFileItemFactory dfif = new DiskFileItemFactory();
		dfif.setSizeThreshold(1024 * 5);// 设置上传文件时用于临时存放文件的内存大小,这里是5k.多于的部分将临时存在硬盘
		dfif.setRepository(new File(tempPath));// 设置存放临时文件的目录

		//用以上工厂实例化上传组件
		ServletFileUpload sfu = new ServletFileUpload(dfif);
		//设置最大上传尺寸
		sfu.setSizeMax(MAX_SIZE);

		PrintWriter out = response.getWriter();
		final HttpSession session = request.getSession();
		
		sfu.setProgressListener(new ProgressListener() {
			private long temp = -1;
		    public void update(long readBytes, long totalBytes, int item) {
				long size = readBytes / 1024 * 1024 * 10;
				if(temp == size){
					return;
				}
				temp = size;
				if (readBytes != -1) {
					session.setAttribute("readBytes", "" + readBytes);
				    session.setAttribute("totalBytes", "" + totalBytes);
				}
		    }
		});
		
		//从request得到 所有 上传域的列表
		List fileList = null;
		try {
			fileList = sfu.parseRequest(request);
		} catch (FileUploadException e) {//处理文件尺寸过大异常
			if (e instanceof SizeLimitExceededException) {
				if(null != jsonp && !"".equals(jsonp)){
					out.println("<script type='text/javascript' id='" + jsonp + "'>parent." + jsonp + "({statusText:'上传文件大小不能超过1G'});setTimeout(function(){delete parent." + jsonp + ";var s=document.getElementById('" + jsonp + "');s.parentNode.removeChild(s);},50);</script>");
				}else{
					out.println("上传文件大小不能超过1G");
				}
				return;
			}
			e.printStackTrace();
		}
		//没有选择上传文件
		if (fileList == null || fileList.size() == 0) {
			if(null != jsonp && !"".equals(jsonp)){
				out.println("<script type='text/javascript' id='" + jsonp + "'>parent." + jsonp + "({statusText:'请选择上传文件'});setTimeout(function(){delete parent." + jsonp + ";var s=document.getElementById('" + jsonp + "');s.parentNode.removeChild(s);},50);</script>");
			}else{
				out.println("请选择上传文件");
			}
			return;
		}
		//得到所有上传的文件
		Iterator fileItr = fileList.iterator();
		//循环处理所有文件
		while (fileItr.hasNext()) {
			FileItem fileItem = null;
			String path = null;
			double size = 0;
			//得到当前文件
			fileItem = (FileItem) fileItr.next();
			//忽略简单form字段而不是上传域的文件域(<input type="text" />等)
			if (fileItem == null || fileItem.isFormField()) {
				continue;
			}
			//得到文件的完整路径
			path = fileItem.getName();
			//得到文件的大小
			size = fileItem.getSize();
			if ("".equals(path) || size == 0) {
				if(null != jsonp && !"".equals(jsonp)){
					out.println("<script type='text/javascript' id='" + jsonp + "'>parent." + jsonp + "({statusText:'请选择上传文件'});setTimeout(function(){delete parent." + jsonp + ";var s=document.getElementById('" + jsonp + "');s.parentNode.removeChild(s);},50);</script>");
				}else{
					out.println("请选择上传文件");
				}
				return;
			}
			//得到去除路径的文件名
			String t_name = path.substring(path.lastIndexOf("\\") + 1);
			//得到文件的扩展名(无扩展名时将得到全名)
			String t_ext = t_name.substring(t_name.lastIndexOf(".") + 1);
			//保存的最终文件完整路径,保存在e盘upload目录下
			String u_name = filePath + t_name + "." + t_ext;
			String u_size = "";
			try {
				//保存文件
				fileItem.write(new File(u_name));
				if(size > 1024 * 1024)
					u_size = (float)Math.round(size * 100 / (1024 * 1024)) / 100 + "MB";
				else
					u_size = (float)Math.round(size * 100 / 1024) / 100 + "KB";
				if(null != jsonp && !"".equals(jsonp)){
					out.println("<script type='text/javascript' id='" + jsonp + "'>parent." + jsonp + "({statusText:'文件名：" + t_name + "<br/>上传完成。<br/>文件大小：" + u_size + "'});setTimeout(function(){delete parent." + jsonp + ";var s=document.getElementById('" + jsonp + "');s.parentNode.removeChild(s);},50);</script>");
				}else{
					out.println("文件名：" + t_name + "<br/>上传完成。<br/>文件大小：" + u_size);
				}
			} catch (Exception e) {
				e.printStackTrace();
			}

		}
	}

}
