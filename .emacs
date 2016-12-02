
(global-set-key (kbd "M-n") 'other-window);

(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(inhibit-startup-screen t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Hack" :foundry "outline" :slant normal :weight normal :height 83 :width normal)))))
(load-file "~/cherryblossom.el")
(defun compile-tags ()
  "compile etags for the current project"
  (interactive)
  (cd "~/kraken")
  (compile "etags -R *.c *.h"))

(setq default-directory "~/kraken/")
