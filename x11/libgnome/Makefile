# New ports collection makefile for:	libgnome
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	libgnome
PORTVERSION=	2.0.1
CATEGORIES?=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	pre-gnome2/releases/gnome-2.0-desktop-rc1
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org

LIB_DEPENDS+=	xslt.1:${PORTSDIR}/textproc/libxslt \
		gnomevfs-2.0:${PORTSDIR}/devel/gnomevfs2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_ESOUND=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-html-dir=${PREFIX}/share/doc \
		--with-gconf-source=xml::${PREFIX}/etc/gconf/gconf.xml.defaults
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|\$\(libdir\)/pkgconfig|\$\(prefix\)/libdata/pkgconfig|g ; \
		 s|\$\(libdir\)/bonobo/servers|\$\(prefix\)/libdata/bonobo/servers|g'

.include <bsd.port.mk>
