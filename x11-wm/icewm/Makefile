# New ports collection makefile for:	icewm
# Date created:		10 August 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	icewm
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		giconv.2:${PORTSDIR}/converters/libiconv

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WANT_GNOME=	yes
WANT_ESOUND=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
#USE_AUTOCONF_VER=213
USE_AUTOCONF_VER=252
AUTOCONF=	autoconf
AUTOCONF_DIR=	${LOCALBASE}/share/autoconf
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-i18n --enable-nls \
		--with-cfgdir=${PREFIX}/share/icewm \
		--with-libdir=${PREFIX}/share/icewm \
		--with-kdedatadir=${LOCALBASE}/share \
		--with-docdir=${PREFIX}/share/doc

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS+=	--with-imlib --without-xpm --with-gnome-menus
INSTALL_TARGET=		install install-gnome
.else
USE_XPM=	yes
CONFIGURE_ARGS+=	--without-imlib --with-xpm --without-gnome-menus
.endif

post-install:
	${INSTALL_DATA} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/share/icewm/taskbar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/icewm
.for file in CHANGES FAQ INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/icewm
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/icewm
.endif
	${CHOWN} root.kmem ${PREFIX}/bin/icewm
	${CHMOD} 2555 ${PREFIX}/bin/icewm

.include <bsd.port.post.mk>
