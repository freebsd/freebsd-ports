# New ports collection makefile for:	KDE libraries 2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES?=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

BUILD_DEPENDS=	automake14:${PORTSDIR}/devel/automake14 \
		autoconf213:${PORTSDIR}/devel/autoconf213
.if ${MACHINE_ARCH} == "i386" && !defined(NO_KDE_OBJPRELINK)
BUILD_DEPENDS+=	objprelink:${PORTSDIR}/devel/objprelink
.endif
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		fam.0:${PORTSDIR}/devel/fam \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		pcre.0:${PORTSDIR}/devel/pcre \
		cups.2:${PORTSDIR}/print/cups-base \
		xslt.1:${PORTSDIR}/textproc/libxslt
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_OPENSSL=	yes
USE_QT_VER=	2
SOMAJOR=	4
SOMINOR=	0
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-cups --disable-ltdl-install
.if ${MACHINE_ARCH} == "i386" && !defined(NO_KDE_OBJPRELINK)
CONFIGURE_ARGS+=--enable-objprelink
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.else
CONFIGURE_ARGS+=--enable-debug
STRIP=''
.endif

.if ${MACHINE_ARCH} == "alpha"
CFLAGS=		-O0 ${KDE_CFLAGS} -D__PATH_SU=/usr/bin/su
.endif

USE_GMAKE=	yes
MAKE_ENV=	SOMAJOR="${SOMAJOR}" SOMINOR="${SOMINOR}"
PLIST_SUB+=	LIBVER="${SOMAJOR}" LDCONFIG="${LDCONFIG}"

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} <= 410002
	@${ECHO}
	@${ECHO} "			NOTICE"
	@${ECHO}
	@${ECHO} "Your OpenSSL installation could be out of date.  This is"
	@${ECHO} "just a warning, but if your system's world was built on"
	@${ECHO} "sources earlier than August 20 along RELENG_4 or older,"
	@${ECHO} "then KDE2 will not build with SSL support."
	@${ECHO}
.endif

pre-extract:
.if exists(${LOCALBASE}/include/kfm.h)
	@${ECHO}
	@${ECHO} "			NOTICE"
	@${ECHO}
	@${ECHO} "You have KDE1 headers installed!  Installing this port"
	@${ECHO} "will result in conflicts between KDE2 and KDE1!"
	@${ECHO}
	@${FALSE}
.endif

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs
	${PERL} -pi -e "s@-O2@-O0@g; s@\"-lfam@\"-L${LOCALBASE}/lib -lfam@g" ${WRKSRC}/configure
	${PERL} -pi -e "s@kspell api@@g" ${WRKSRC}/doc/Makefile.in
	(find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi.orig -e \
		"s@version-info 1:0@version-info ${SOMAJOR}:${SOMINOR}@g; \
		 s@version-info 3:0@version-info ${SOMAJOR}:${SOMINOR}@g")

post-configure:
	${PERL} -pi -e "s@-D_PTH_H_ -D_PTH_PTHREAD_H_@@g" ${WRKSRC}/arts/mcop_mt/Makefile

post-install:
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/kdelibs.sh > ${PREFIX}/etc/rc.d/kdelibs.sh
	${CHMOD} 755 ${PREFIX}/etc/rc.d/kdelibs.sh
.for LIB in DCOP kab kdecore kdesu kdeui kfile kio kjs kparts kspell \
	    ksycoca kjava
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.${SOMAJOR} ${PREFIX}/lib/lib${LIB}.so
.endfor
.for LIB in artsc artsflow artsflow_idl kmid kmedia2_idl qtmcop soundserver_idl
	@${LN} -sf ${PREFIX}/lib/lib${LIB}.so.0 ${PREFIX}/lib/lib${LIB}.so
.endfor

.include <bsd.port.post.mk>
