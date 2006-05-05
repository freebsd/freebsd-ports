# New ports collection makefile for:	alltray
# Date created:		2005-10-15
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	alltray
PORTVERSION=	0.66
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	alltray

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Dock any application with no native tray icon

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 gconf2
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" LDFLAGS="-L${X11BASE}/lib"
USE_GCC=	3.4+

MAN1=		alltray.1

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's|-L/usr/X11R6/lib||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|/etc/gconf|${X11BASE}/etc/gconf|; \
		/THEME_DIR1/ s|/usr/share/|${X11BASE}/share/gnome/themes/|' \
		${WRKSRC}/src/gnome_theme.c
	@${REINPLACE_CMD} -e 's|liballtray\.so\.0\.0\.0|liballtray.so.0|; \
		s|/usr/lib|${PREFIX}/lib|' ${WRKSRC}/src/child.c

.include <bsd.port.mk>
