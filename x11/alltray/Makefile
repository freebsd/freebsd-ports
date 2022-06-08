# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>

PORTNAME=	alltray
PORTVERSION=	0.70
PORTREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Dock any application with no native tray icon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	abandonware
EXPIRATION_DATE=	2022-07-08

USES=		gnome libtool pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
# Upstream seems dead. Don't expect a proper fix.
CFLAGS+=	-fcommon
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-gconf

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
