# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	alltray
PORTVERSION=	0.70
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Dock any application with no native tray icon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	KDE
KDE_DESC=	Support only KDE desktop
KDE_CONFIGURE_ON=	--disable-gconf

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MKDE}
USE_GNOME+=	gconf2
.endif

post-patch:
	@${CHMOD} +x ${WRKSRC}/install-sh
	@${REINPLACE_CMD} \
		-e 's|-ldl||' -e '/^liballtray_la_LIBADD =/s/$$/ -lX11/' \
		${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} \
		-e 's|-L/usr/X11R6/lib||' -e '/^alltray_LDADD =/s/$$/ -lX11/' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|/etc/gconf|${LOCALBASE}/etc/gconf|; \
		/THEME_DIR1/ s|/usr/share/|${LOCALBASE}/share/themes/|' \
		${WRKSRC}/src/gnome_theme.c
	@${REINPLACE_CMD} 's|/usr/lib|${PREFIX}/lib|' ${WRKSRC}/src/child.c

.include <bsd.port.mk>
