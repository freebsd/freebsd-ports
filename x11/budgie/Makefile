PORTNAME=	budgie
PORTVERSION=	10.9
CATEGORIES=	x11 budgie

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Meta-port for the Budgie Desktop Environment
WWW=		https://buddiesofbudgie.org/

RUN_DEPENDS=	budgie-desktop:x11/budgie-desktop \
		budgie-desktop-view>0:deskutils/budgie-desktop-view \
		budgie-control-center:sysutils/budgie-control-center \
		adwaita-icon-theme>0:x11-themes/adwaita-icon-theme \
		tela-icon-theme>0:x11-themes/tela-icon-theme \
		xdg-user-dirs>0:devel/xdg-user-dirs

# Additional wallpapers
RUN_DEPENDS+=	budgie-backgrounds>0:x11-themes/budgie-backgrounds

RUN_DEPENDS+=	gnome-terminal>0:x11/gnome-terminal \
		nautilus>0:x11-fm/nautilus \
		lightdm-gtk-greeter>0:x11/lightdm-gtk-greeter

USES=		metaport

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

EXAMPLES_SUB_FILES=	pkg-message xprofile

pre-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

post-install-EXAMPLES-on:
	${INSTALL_SCRIPT} ${WRKDIR}/xprofile ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
