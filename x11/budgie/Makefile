PORTNAME=	budgie
PORTVERSION=	10.7
PORTREVISION=	1
CATEGORIES=	x11 budgie

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Meta-port for the Budgie Desktop Environment
WWW=		https://blog.buddiesofbudgie.org/

RUN_DEPENDS=	budgie-desktop>0:x11/budgie-desktop \
		budgie-desktop-view>0:deskutils/budgie-desktop-view \
		budgie-control-center>0:sysutils/budgie-control-center \
		qogir-gtk-themes>0:x11-themes/qogir-gtk-themes \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme \
		tela-icon-theme>0:x11-themes/tela-icon-theme \
		xdg-user-dirs>0:devel/xdg-user-dirs

# Additional wallpapers
RUN_DEPENDS+=	budgie-backgrounds>0:x11-themes/budgie-backgrounds

# Additional applets
RUN_DEPENDS+=	budgie-trash-applet>0:deskutils/budgie-trash-applet

RUN_DEPENDS+=	gnome-terminal>0:x11/gnome-terminal \
		nautilus>0:x11-fm/nautilus \
		lightdm-gtk-greeter>0:x11/lightdm-gtk-greeter

USES=		metaport

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

EXAMPLES_SUB_FILES=	pkg-message xinitrc xprofile

pre-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

post-install-EXAMPLES-on:
.for f in xinitrc xprofile
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
