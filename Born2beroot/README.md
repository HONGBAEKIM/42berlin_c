# reference

DOWNLOAD DEBIAN
https://www.debian.org/

THEN GO TO YOUTUBE AND FOLLOW THIS
https://www.youtube.com/watch?v=OQEdjt38ZJA

MY FAV (ALSO FOR BONUS PART)
https://github.com/mcombeau/Born2beroot/blob/main/guide/bonus_debian.md

THIS ONE IS VERY DETAILED but some mistakes on cron and bonus
https://github.com/caroldaniel/42sp-cursus-born2beroot/blob/master/guides/Debian-en.md

THIS IS GOOD TOO
https://github.com/hanshazairi/42-born2beroot#installation

THIS IS ESSENTIAL FOR THE EVAL
https://github.com/PublioElio/School-42-Born2beroot#apparmor-application-armor

Good eval guide:
https://github.com/HEADLIGHTER/Born2BeRoot-42/blob/main/evalknwoledge.txt

Some helpful commands
    sha1sum born2beroot.vdi
    $ lsblk (shows partitions)
    php -v (this checks php status by telling u what version is installed)
    
Users and groups
    getent group groupname (this checks who is in a group)
    $ id -Gn <username>
    sudo adduser username (creates user)
    sudo adduser username group (adds to group)
    getent group user42 (check everyone in user42 group)
    hostname (tells u the hostname)
    sudo groupadd evaluating
    sudo hostnamectl set-hostname <new-hostname>
    
Passwords & security
    sudo nano /etc/security/pwquality.conf (shows the file with password settings)
    sudo nano /etc/login.defs (shows the other file with passwd configurations)
    sudo -V (shows that sudo is active)
    sudo nano /var/log/sudo/sudo.log (shows the list of logs)
    
Etc
    lsb_release -a (shows the operating system)
    sudo systemctl status ssh.service (shows that ssh is active...for eval)
    groups username (shows what groups the user is in)
    sudo systemctl status fail2ban (IF you install fail2ban for bonus, it shows it is active in eval)
    $ sudo hostnamectl set-hostname <new_hostname> (creates new hostname no need to reboot)
    $ sudo nano /etc/hostname (modify hostname in the file active if you reboot first)
    $ sudo nano /var/log/sudo/sudo.log (shows sudo files log)
    su username (su stands for switch user)
    
FireWall    
    sudo ufw allow 8080 (allows access to port 8080)
    sudo ufw status numbered
    sudo ufw delete 5 (deletes rule number 5)
    # sudo nano /etc/ssh/sshd_config (check/modify sssh configuration)
    $ sudo fail2ban-client status sshd (command to check fail2ban status re sshd)
    $ sudo tail -f /var/log/fail2ban.log (command to check log of fail2ban)
    $ sudo apt install telnet
    sudo aa-status (check App Armor status)

Crontab
    sudo systemctl stop cron.service (stop cron without deleting script)
    $ crontab -e (shows the cron command line)
    sudo crontab -l (Check Crontab settings)

Wordpress
    ip addr show        (shows your ip address)
    http://127.0.0.1:8080/
    

SSh status check
     systemctl status sshd
    
    
VIDEO ON HOW TO CONFIGURE WORDPRESS WEBSITE (IF U WANNA MAKE IT PRETTY)
https://cdn.intra.42.fr/video/video/82/low_d_WordPress-1.mp4

# before git push
https://github.com/HEADLIGHTER/Born2BeRoot-42/blob/main/evalknwoledge.txt
