# New ports collection makefile for:	icewm
# Date created:		10 August 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	icewm
PORTVERSION=	1.2.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-i18n --enable-nls \
		--with-cfgdir=${PREFIX}/share/icewm \
		--with-libdir=${PREFIX}/share/icewm \
		--with-kdedatadir=${LOCALBASE}/share \
		--with-docdir=${PREFIX}/share/doc \
		--with-mkfontdir=${NONEXISTENT}

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
.undef HAVE_ESOUND
USE_GNOME+=	gnomelibs
CONFIGURE_ARGS+=	--with-imlib --without-xpm --with-gnome-menus \
			--enable-guievents --with-icesound=esound
INSTALL_TARGET=		install install-gnome
PLIST_SUB+=	ESOUND=""
.else
USE_XPM=	yes
CONFIGURE_ARGS+=	--without-imlib --with-xpm --without-gnome-menus
.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-guievents --with-icesound=esound
PLIST_SUB+=	ESOUND=""
.else
PLIST_SUB+=	ESOUND="@comment "
.endif
.endif

pre-configure:
	@cd ${CONFIGURE_WRKSRC} && ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA} ${FILESDIR}/bsd-daemon.xpm ${DATADIR}/taskbar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES FAQ INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif
	${CHOWN} root:kmem ${PREFIX}/bin/icewm
	${CHMOD} 2555 ${PREFIX}/bin/icewm

.include <bsd.port.post.mk>
