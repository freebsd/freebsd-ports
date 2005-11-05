# New ports collection makefile for:	alltray
# Date created:		2005-10-15
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	alltray
PORTVERSION=	0.62
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	alltray

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Dock any application with no native tray icon

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
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

patch-autotools:
	@for file in ${LIBTOOLFILES}; do \
		${REINPLACE_CMD} -e \
			'/^ltmain=/ s|$$ac_aux_dir/ltmain\.sh|${LTMAIN}|g' \
			${PATCH_WRKSRC}/$$file; \
	done

.include <bsd.port.mk>
