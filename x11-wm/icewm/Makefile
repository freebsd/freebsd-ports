# New ports collection makefile for:	icewm
# Date created:		10 August 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	icewm
PORTVERSION=	1.2.13
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Manager designed for speed, usability and consistency

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_X_PREFIX=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--enable-shaped-decorations \
		--enable-guievents \
		--with-cfgdir=${DATADIR} \
		--with-libdir=${DATADIR} \
		--with-kdedatadir=${LOCALBASE}/share \
		--with-docdir=${PREFIX}/share/doc \
		--with-mkfontdir=${NONEXISTENT}

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomedesktop}!=""
USE_GNOME+=	gnomedesktop
CONFIGURE_ARGS+=	--enable-menus-gnome2
INSTALL_TARGET=		install install-gnome
PLIST_SUB+=	GNOMEDESKTOP=""
PKGNAMESUFFIX=	-gnome
.else
PLIST_SUB+=	GNOMEDESKTOP="@comment "
.endif

.if ${HAVE_GNOME:Mimlib}!=""
USE_GNOME+=	imlib
CONFIGURE_ARGS+=	--with-imlib
.else
USE_XPM=	yes
CONFIGURE_ARGS+=	--without-imlib
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--with-icesound=esound
.else
CONFIGURE_ARGS+=	--with-icesound=oss
.endif

.if ${XFREE86_VERSION} < 4 || defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--enable-corefonts --disable-xfreetype
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/Xft
.endif

.if ${XFREE86_VERSION} < 4 || defined(WITHOUT_XINERAMA)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.if ${ARCH} != "i386" || defined(WITHOUT_X86_ASM)
CONFIGURE_ARGS+=	--disable-x86-asm
.endif

post-patch:
.for file in src/gnome2.cc
	@${REINPLACE_CMD} -e \
		's|/usr/share/control|${X11BASE}/share/gnome/control|g ; \
		 s|/usr/share/app|${X11BASE}/share/gnome/app|g ; \
		 s|/usr/share/gnome|${X11BASE}/share/gnome|g' ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/bsd-daemon.xpm ${DATADIR}/taskbar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif
	${CHOWN} root:kmem ${PREFIX}/bin/icewm
	${CHMOD} 2555 ${PREFIX}/bin/icewm

.include <bsd.port.post.mk>
